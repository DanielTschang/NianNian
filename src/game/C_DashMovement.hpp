#ifndef NIANNIAN_C_DASHMOVEMENT_HPP
#define NIANNIAN_C_DASHMOVEMENT_HPP


#include "Component.hpp"
#include "Input.hpp"
#include "C_Animation.hpp"
#include "Object.hpp"
#include "CooldownTimer.hpp"

class Object;


class C_DashMovement : public Component
{
public:
    C_DashMovement(Object * owner);
    void SetInput(Input* input);
    void setDashDistant(float distant);
    void setCooldown(float cd);
    void Update(const float& deltaTime) override;
    void Awake();


private:
    float dashDistant;
    CooldownTimer* cooldownTimer;
    Input* input;
    std::shared_ptr<C_Animation> animation;
};

#endif //NIANNIAN_C_DASHMOVEMENT_HPP
