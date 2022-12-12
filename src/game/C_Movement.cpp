#include "C_Movement.hpp"
#include "Object.hpp"

C_Movement::C_Movement(Object* owner): 
    Component(owner), moveSpeed(100) {}

void C_Movement::SetInput(Input* input)
{
  this->input = input;
}

void C_Movement::SetMovementSpeed(int moveSpeed)
{
  this->moveSpeed = moveSpeed;
}

void C_Movement::Update(float deltaTime)
{
    if(input == nullptr) return;

    int xMove = 0;
    if(input->IsKeyPressed(Input::KEY::LEFT))
    {
        std::cout << "yo\n";
        xMove -= moveSpeed;
    }

    if(input->IsKeyPressed(Input::KEY::RIGHT))
        xMove += moveSpeed;

    int yMove = 0;
    if(input->IsKeyPressed(Input::KEY::UP))
        yMove -= moveSpeed;
    if(input->IsKeyPressed(Input::KEY::DOWN))
        yMove += moveSpeed;
    
    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;
    
    owner->position->AddPosition(xFrameMove, yFrameMove);
}