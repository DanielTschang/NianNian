#include "C_Movement.hpp"


C_Movement::C_Movement(Object* owner):
        Component(owner) {}

void C_Movement::Update(const float& deltaTime)
{
    //TODO: movement component shouldn't interact with any animation component
    if(animation->GetAnimationState() == AnimationState::Attack)
    {
        return;
    }
    this->detectKeyboard();
}




void C_Movement::Awake()
{
    animation = owner->GetComponent<C_Animation>();
    velocity = owner->GetComponent<C_Velocity>();
}

//void C_Movement::LateUpdate(const float &deltaTime) {
//    //deceleration
//    if(this->currentSpeedX > 0.f)
//    {
//        this->currentSpeedX -= this->deceleration;
//        if(this->currentSpeedX <= 0.f) this->currentSpeedX = 0.f;
//    }
//    else if(this->currentSpeedX < 0.f)
//    {
//        this->currentSpeedX += this->deceleration;
//        if(this->currentSpeedX >= 0.f) this->currentSpeedX = 0.f;
//    }
//
//    if(this->currentSpeedY > 0.f)
//    {
//        this->currentSpeedY -= this->deceleration;
//        if(this->currentSpeedY <= 0.f) this->currentSpeedY = 0.f;
//    }
//    else if(this->currentSpeedY < 0.f)
//    {
//        this->currentSpeedY += this->deceleration;
//        if(this->currentSpeedY >= 0.f) this->currentSpeedY = 0.f;
//    }
//
//}

C_Movement::~C_Movement() {

}



void C_Movement::detectKeyboard() {
    auto currentVelocity = velocity->Get();
    float currentX = currentVelocity.x;
    float currentY = currentVelocity.y;
    float acceleration = velocity->getAcceleration();
    if(owner->context->input->IsKeyPressed(Input::KEY::LEFT))
    {
//        animation->SetAnimationDirection(FacingDirection::Left);
        currentX -= acceleration;
    }

    if(owner->context->input->IsKeyPressed(Input::KEY::RIGHT)) {
        currentX += acceleration;
    }


    if(owner->context->input->IsKeyPressed(Input::KEY::UP)) {
        currentY -= acceleration;
    }
    if(owner->context->input->IsKeyPressed(Input::KEY::DOWN)) {
        currentY += acceleration;
    }

    this->velocity->Set(currentX, currentY);

}

