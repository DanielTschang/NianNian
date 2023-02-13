#include "Object.hpp"

Object::Object()
{
    position = AddComponent<C_Position>();
}

void Object::Awake()
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Awake();
    }
}

void Object::Start()
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Start();
    }
}

void Object::Update(const float& timeDelta)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Update(timeDelta);
    }
}

void Object::LateUpdate(const float& timeDelta)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->LateUpdate(timeDelta);
    }
}

void Object::Draw(Window& window)
{
    for(int i = components.size() - 1; i >= 0; i--)
    {
        components[i]->Draw(window);
    }
}

void Object::QueueForRemoval()
{
    return;
}

bool Object::IsQueuedForRemoval()
{
    return false;
}

Object::~Object() {

}
