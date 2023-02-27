#include "C_Velocity.hpp"
C_Velocity::C_Velocity(Object* owner) : Component(owner), maxVelocity(200.f, 200.f), acceleration(10), deceleration(5)
{ }

void C_Velocity::Update(const float& deltaTime)
{
    owner->position->AddPosition(this->velocity.x * deltaTime, this->velocity.y* deltaTime);
}

void C_Velocity::SetMaxVelocity(const sf::Vector2f maxVelocity)
{
    this->maxVelocity = maxVelocity;
}

void C_Velocity::SetMaxVelocity(const float maxVelocityX, const float maxVelocityY)
{

    this->maxVelocity = sf::Vector2f(maxVelocityX, maxVelocityY);
}

void C_Velocity::Set(const sf::Vector2f& vel)
{
    velocity = vel;

    ClampVelocity();
}


void C_Velocity::Set(float x, float y)
{
    velocity.x = x;
    velocity.y = y;

    ClampVelocity();
}


void C_Velocity::ClampVelocity()
{
    if (fabs(velocity.x) > maxVelocity.x)
    {
        if (velocity.x > 0.f)
        {
            velocity.x = maxVelocity.x;
        }
        else
        {
            velocity.x = -maxVelocity.x;
        }
    }

    if (fabs(velocity.y) > maxVelocity.y)
    {
        if (velocity.y > 0.f)
        {
            velocity.y = maxVelocity.y;
        }
        else
        {
            velocity.y = -maxVelocity.y;
        }
    }
}

void C_Velocity::LateUpdate(const float &deltaTime) {
    //deceleration
    float currentVelocityX = static_cast<float>(this->velocity.x);
    float currentVelocityY = static_cast<float>(this->velocity.y);
    if(currentVelocityX > 0.f)
    {
        this->velocity.x -= this->deceleration;
        if(this->velocity.x <= 0.f) this->velocity.x = 0.f;
    }
    else if(currentVelocityX < 0.f)
    {
        this->velocity.x += this->deceleration;
        if(this->velocity.x >= 0.f) this->velocity.x = 0.f;
    }

    if(currentVelocityY > 0.f)
    {
        this->velocity.y -= this->deceleration;
        if(this->velocity.y <= 0.f) this->velocity.y = 0.f;
    }
    else if(currentVelocityY < 0.f)
    {
        this->velocity.y += this->deceleration;
        if(this->velocity.y >= 0.f) this->velocity.y = 0.f;
    }
}

float C_Velocity::getAcceleration() {
    return this->acceleration;
}

float C_Velocity::getDecleration() {
    return this->deceleration;
}

const sf::Vector2f &C_Velocity::Get() const {
    return this->velocity;
}

