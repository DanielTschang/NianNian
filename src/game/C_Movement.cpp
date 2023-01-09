#include "C_Movement.hpp"


C_Movement::C_Movement(Object* owner): 
    Component(owner), moveSpeed(200) {}

void C_Movement::SetInput(Input* input)
{
  this->input = input;
}

void C_Movement::SetMovementSpeed(int moveSpeed)
{
  this->moveSpeed = moveSpeed;
}

void C_Movement::Update(const float& deltaTime)
{
    if(input == nullptr) return;

    int xMove = 0;
    if(input->IsKeyPressed(Input::KEY::LEFT))
    {
        xMove -= moveSpeed;
        animation->SetAnimationDirection(FacingDirection::Left);
    }

    if(input->IsKeyPressed(Input::KEY::RIGHT)) {
        xMove += moveSpeed;
        animation->SetAnimationDirection(FacingDirection::Right);
    }

    int yMove = 0;
    if(input->IsKeyPressed(Input::KEY::UP))
        yMove -= moveSpeed;
    if(input->IsKeyPressed(Input::KEY::DOWN))
        yMove += moveSpeed;

    if(xMove == 0 && yMove == 0)
    {
        animation->SetAnimationState(AnimationState::Idle);
    }
    else
    {
        animation->SetAnimationState(AnimationState::Walk);
    }
    
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    
    owner->position->AddPosition(xFrameMove, yFrameMove);
}

void C_Movement::Awake()
{
    animation = owner->GetComponent<C_Animation>();
}