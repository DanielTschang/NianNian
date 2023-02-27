#ifndef NIANNIAN_C_VELOCITY_HPP
#define NIANNIAN_C_VELOCITY_HPP

#include <math.h>
#include "Component.hpp"
#include <iostream>
#include "Object.hpp"


class C_Velocity : public Component
{
public:
    C_Velocity(Object* owner);

    void Update(const float& deltaTime) override;
    void LateUpdate(const float& deltaTime) override;



    void Set(const sf::Vector2f& vel);
    void Set(float x, float y);
    const sf::Vector2f& Get() const;


    void SetMaxVelocity(const sf::Vector2f maxVelocity);
    void SetMaxVelocity(const float maxVelocityX, const float maxVelocityY);

    float getAcceleration();
    float getDecleration();

private:
    void ClampVelocity();

    sf::Vector2f velocity;
    sf::Vector2f maxVelocity;
    float acceleration;
    float deceleration;
};

#endif //NIANNIAN_C_VELOCITY_HPP
