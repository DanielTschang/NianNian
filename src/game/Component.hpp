#ifndef Component_hpp
#define Component_hpp

#include "Window.hpp"
// #include "Object.hpp"
class Object;


class Component
{    
public:
    Component(Object* owner) : owner(owner){}
    
    virtual void Awake() {};
    virtual void Start() {};
    
    virtual void Update(const float& deltaTime) {};
    virtual void LateUpdate(const float& deltaTime) {};
    virtual void Draw(Window& window) {};
    
protected:
    Object* owner;
};

#endif