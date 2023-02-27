#ifndef NIANNIAN_C_MOVEMENTANIMATION_HPP
#define NIANNIAN_C_MOVEMENTANIMATION_HPP


#include "Component.hpp"
#include "C_Velocity.hpp"
#include "C_Animation.hpp"
#include "Object.hpp"

class C_MovementAnimation : public Component
{
public:
    C_MovementAnimation(Object* owner);

    void Awake() override;

    void Update(const float &deltaTime) override;

private:
    std::shared_ptr<C_Velocity> velocity;
    std::shared_ptr<C_Animation> animation;
};

#endif //NIANNIAN_C_MOVEMENTANIMATION_HPP
