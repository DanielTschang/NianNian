#ifndef NIANNIAN_OBJECTCOLLECTION_HPP
#define NIANNIAN_OBJECTCOLLECTION_HPP

#include "Object.hpp"
#include <memory>
#include <vector>

class ObjectCollection {
public:
    void Add(std::vector<std::shared_ptr<Object>> &otherObjects);
    void Add(std::shared_ptr<Object> object);
    void Update(float deltaTime);
    void LateUpdate(float deltaTime);
    void Draw(Window& window);
    void ProcessNewObjects(); // This method will be responsible for moving objects added that frame from a temporary new object collection to the main object collection so they are updated, drawn etc.
    void ProcessRemovals();


private:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> newObjects; //this is used to temporarily store recently added objects so that we can choose when they are added to the game by invoking ProcessNewObjects.
};


#endif //NIANNIAN_OBJECTCOLLECTION_HPP
