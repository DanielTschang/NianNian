#ifndef C_Movement_hpp
#define C_Movement_hpp

#include "Component.hpp"
#include "Input.hpp"
// #include "Object.hpp"
class Object;


class C_Movement : public Component
{
  public:
    C_Movement(Object * owner);
    void SetInput(Input* input);
    void SetMovementSpeed(int moveSpeed);
    void Update(float deltaTime) override;
    
  private:
    int moveSpeed; 
    Input* input;
};

#endif /* Movement*/