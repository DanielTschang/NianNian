#ifndef C_Movement_hpp
#define C_Movement_hpp

#include "Component.hpp"
#include "Input.hpp"
#include "C_Animation.hpp"
#include "C_Velocity.hpp"
#include "Object.hpp"
class Object;


class C_Movement : public Component
{
  public:
    C_Movement(Object * owner);
    ~C_Movement();
    void Update(const float& deltaTime) override;
    void Awake();
    
  private:
    float currentSpeedX;
    float currentSpeedY;


    std::shared_ptr<C_Animation> animation;
    std::shared_ptr<C_Velocity> velocity;

    void detectKeyboard();

};

#endif /* Movement*/