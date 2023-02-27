#include "C_BasicAttackAnimation.hpp"


void C_BasicAttackAnimation::animationSetter() {
    if(owner->context->input->IsKeyDown(Input::KEY::CTL))
    {
        animation->SetAnimationState(AnimationState::Attack);
    }else if (owner->context->input->IsKeyUp(Input::KEY::CTL))
    {
        animation->SetAnimationState(AnimationState::Idle);
    }
}

C_BasicAttackAnimation::C_BasicAttackAnimation(Object *owner) : Component(owner) {

}



void C_BasicAttackAnimation::Update(const float& deltaTime)
{
//    this->detectKeyboard();
    this->animationSetter();
}

void C_BasicAttackAnimation::Awake() {
    this->animation = owner->GetComponent<C_Animation>();
}
