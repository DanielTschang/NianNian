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
    void setDashDistant(float distant);
    void setCooldown(float cd);
    void Update(const float& deltaTime) override;
    void Awake() override;


private:
    float dashDistant;
    CooldownTimer* cooldownTimer;
    std::shared_ptr<C_Animation> animation;
};

#endif //NIANNIAN_C_DASHMOVEMENT_HPP
