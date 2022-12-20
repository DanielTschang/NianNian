#pragma once
#include <string>
#include <memory>
#include <map>

template<typename T>
class ResourceAllocator
{
public:
    int Add(const std::string &filePath)
    {
        auto it = resources.find(filePath); //not found--> return resources.end()
        if(it != resources.end()) // we have that type of resource already
        {
            return it->second.first; 
        }

        std::shared_ptr<T> resource = std::make_shared<T>();
        if(!resource->loadFromFile(filePath)) // try load the resource file
        {
            return -1;
        }

        resources.insert(std::make_pair(filePath, std::make_pair(currentID, resource)));
        return currentID++;
    }
    void Remove(int id)
    {
        for(auto it =resources.begin(); it != resources ; it++)
        {
            if(it->second.first == id)
            {
                resources.erase(it);
            }
        }
    }
    std::shared_ptr<T> Get(int id)
    {
        for(auto it = resources.begin(); it != resources.end(); it++)
        {
            if(it->second.first == id)
            {
                return it->second.second;
            }
        }
        return nullptr;
    }
    bool Has(int id)
    {
        return (Get(id)!=nullptr);
    }

private:
    int currentID;
    std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};