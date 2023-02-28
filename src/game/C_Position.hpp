#ifndef C_Position_hpp
#define C_Position_hpp

#include "Component.hpp"
#include <iostream>

class Object;

class C_Position : public Component
{
  public:
    C_Position(Object* owner);
    void setPosition(const float x, const float y);
    void setPosition(const sf::Vector2f& pos);
    
    void AddPosition(const float x, const float y);
    void AddPosition(sf::Vector2f pos);
    
    // Allows us to set x/y values separately.
    void SetX(float x);
    void SetY(float y);
    
    void AddX(float x);
    void AddY(float y);
    
    const sf::Vector2f& getPosition() const;
    
  private:
    sf::Vector2f position;
};

#endif