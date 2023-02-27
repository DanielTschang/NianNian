#include "C_DashMovement.hpp"

C_DashMovement::C_DashMovement(Object *owner) : Component(owner) {
    this->cooldownTimer = new CooldownTimer(3.f);
    this->dashDistant = 20.f;
}


void C_DashMovement::Update(const float &deltaTime) {
    if(owner->context->input == nullptr) return;
    bool isSHIFT = false;
    if(owner->context->input->IsKeyPressed(Input::KEY::SHIFT)) {
        isSHIFT = true;
    }
    if(!isSHIFT || !this->cooldownTimer->isValid()) return;

    short int xMove = 0, yMove = 0;;

    if(owner->context->input->IsKeyPressed(Input::KEY::LEFT))
        xMove -= 1;
    if(owner->context->input->IsKeyPressed(Input::KEY::RIGHT))
        xMove += 1;
    if(owner->context->input->IsKeyPressed(Input::KEY::UP))
        yMove -= 1;
    if(owner->context->input->IsKeyPressed(Input::KEY::DOWN))
        yMove += 1;

    if(xMove >=1){
        owner->position->AddPosition(this->dashDistant,0);
        this->cooldownTimer->restartCooldown();
    }
    if(yMove >=1 ){
        owner->position->AddPosition(0,this->dashDistant);
        this->cooldownTimer->restartCooldown();
    }
    if(xMove <= -1){
        owner->position->AddPosition(-1 * this->dashDistant,0);
        this->cooldownTimer->restartCooldown();
    }
    if(yMove <= -1){
        owner->position->AddPosition(0,-1 * this->dashDistant);
        this->cooldownTimer->restartCooldown();
    }

}

void C_DashMovement::Awake() {

}

void C_DashMovement::setDashDistant(float distant) {
    this->dashDistant = distant;
}

void C_DashMovement::setCooldown(float cd) {
    this->cooldownTimer->setCooldown(cd);
}

