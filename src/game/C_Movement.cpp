#include "C_Movement.hpp"


C_Movement::C_Movement(Object* owner):
        Component(owner), maxMoveSpeed(200), acceleration(5), deceleration(3), currentSpeedX(0), currentSpeedY(0) {}

void C_Movement::SetInput(Input* input)
{
  this->input = input;
}

void C_Movement::SetMovementSpeed(float maxMoveSpeed)
{
  this->maxMoveSpeed = maxMoveSpeed;
}

void C_Movement::Update(const float& deltaTime)
{
    this->detectKeyboard();
    this->exceedMaxSpeedChecker();
    this->animationSetter();
    this->updatePosition(deltaTime);

}

void C_Movement::exceedMaxSpeedChecker() {
    if(this->currentSpeedX > 0.f)
    {
        if(this->currentSpeedX > this->maxMoveSpeed) this->currentSpeedX = this->maxMoveSpeed;
    }
    else if(this->currentSpeedX < 0.f)
    {
        if(this->currentSpeedX < -this->maxMoveSpeed) this->currentSpeedX = -this->maxMoveSpeed;
    }

    if(this->currentSpeedY > 0.f)
    {
        if(this->currentSpeedY > this->maxMoveSpeed) this->currentSpeedY = this->maxMoveSpeed;
    }
    else if(this->currentSpeedY < 0.f)
    {
        if(this->currentSpeedY < -this->maxMoveSpeed) this->currentSpeedY = -this->maxMoveSpeed;
    }
}


void C_Movement::Awake()
{
    animation = owner->GetComponent<C_Animation>();
}

void C_Movement::LateUpdate(const float &deltaTime) {
    //deceleration
    if(this->currentSpeedX > 0.f)
    {
        this->currentSpeedX -= this->deceleration;
        if(this->currentSpeedX <= 0.f) this->currentSpeedX = 0.f;
    }
    else if(this->currentSpeedX < 0.f)
    {
        this->currentSpeedX += this->deceleration;
        if(this->currentSpeedX >= 0.f) this->currentSpeedX = 0.f;
    }

    if(this->currentSpeedY > 0.f)
    {
        this->currentSpeedY -= this->deceleration;
        if(this->currentSpeedY <= 0.f) this->currentSpeedY = 0.f;
    }
    else if(this->currentSpeedY < 0.f)
    {
        this->currentSpeedY += this->deceleration;
        if(this->currentSpeedY >= 0.f) this->currentSpeedY = 0.f;
    }

}

C_Movement::~C_Movement() {

}

void C_Movement::animationSetter() {
    if(this->currentSpeedX == 0 && this->currentSpeedY == 0)
    {
        this->animation->SetAnimationState(AnimationState::Idle);
    }
    else
    {
        this->animation->SetAnimationState(AnimationState::Walk);
    }
}

void C_Movement::detectKeyboard() {
    if(input == nullptr) return;

    if(input->IsKeyPressed(Input::KEY::LEFT))
    {
        animation->SetAnimationDirection(FacingDirection::Left);
        currentSpeedX -= this->acceleration;
    }

    if(input->IsKeyPressed(Input::KEY::RIGHT)) {
        animation->SetAnimationDirection(FacingDirection::Right);
        currentSpeedX += this->acceleration;
    }


    if(input->IsKeyPressed(Input::KEY::UP)) {
        currentSpeedY -= this->acceleration;
    }
    if(input->IsKeyPressed(Input::KEY::DOWN)) {
        currentSpeedY += this->acceleration;
    }

}

void C_Movement::updatePosition(const float& deltaTime) {
    float xFrameMove = currentSpeedX * deltaTime;
    float yFrameMove = currentSpeedY * deltaTime;
    owner->position->AddPosition(xFrameMove, yFrameMove);
}

