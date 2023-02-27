#ifndef NIANNIAN_C_BASICATTACKANIMATION_HPP
#define NIANNIAN_C_BASICATTACKANIMATION_HPP


#include "Component.hpp"
#include "Input.hpp"
#include "C_Animation.hpp"
#include "Object.hpp"

class C_BasicAttackAnimation : public Component
{
public:
    C_BasicAttackAnimation(Object * owner);
    void Awake() override;
    void Update(const float& deltaTime) override;

private:
    std::shared_ptr<C_Animation> animation;
    void animationSetter();
};

#endif //NIANNIAN_C_BASICATTACKANIMATION_HPP
