#ifndef C_Movement_hpp
#define C_Movement_hpp

#include "Component.hpp"
#include "Input.hpp"
#include "C_Animation.hpp"
#include "Object.hpp"
class Object;


class C_Movement : public Component
{
  public:
    C_Movement(Object * owner);
    void SetInput(Input* input);
    void SetMovementSpeed(int moveSpeed);
    void Update(const float& deltaTime) override;
    void Awake();
    
  private:
    int moveSpeed; 
    Input* input;
    std::shared_ptr<C_Animation> animation;
};

#endif /* Movement*/