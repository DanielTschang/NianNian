#include "ObjectCollection.hpp"

void ObjectCollection::Update(float deltaTime)
{
    for(auto& o : objects)
    {
        o->Update(deltaTime);
    }
}

void ObjectCollection::LateUpdate(float deltaTime)
{
    for(auto& o : objects)
    {
        o->LateUpdate(deltaTime);
    }
}

void ObjectCollection::Draw(Window& window)
{
    for(auto& o : objects)
    {
        o->Draw(window);
    }
}

void ObjectCollection::Add(std::vector<std::shared_ptr<Object>>& otherObjects)
{
    newObjects.insert(newObjects.end(), otherObjects.begin(), otherObjects.end());
}

void ObjectCollection::Add(std::shared_ptr<Object> object)
{
    newObjects.push_back(object);
}

void ObjectCollection::ProcessNewObjects()
{
    if (!newObjects.empty())
    {
        for (const auto& o : newObjects)
        {
            o->Awake();
        }

        for (const auto& o : newObjects)
        {
            o->Start();
        }

        objects.insert(objects.end(), newObjects.begin(), newObjects.end());

        newObjects.clear();
    }
}

void ObjectCollection::ProcessRemovals()
{
    auto objIterator = objects.begin();
    while (objIterator != objects.end())
    {
        auto obj = **objIterator;
        if (obj.IsQueuedForRemoval())
        {
            objIterator = objects.erase(objIterator);
        }
        else
        {
            ++objIterator;
        }
    }
}