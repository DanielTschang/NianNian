#ifndef C_Position_hpp
#define C_Position_hpp

#include "Component.hpp"

class Object;

class C_Position : public Component
{
  public:
    C_Position(Object* owner);
    void SetPosition(const float x, const float y);
    void SetPosition(const sf::Vector2f& pos);
    
    void AddPosition(const float x, const float y);
    void AddPosition(sf::Vector2f pos);
    
    // Allows us to set x/y values separately.
    void SetX(float x);
    void SetY(float y);
    
    void AddX(float x);
    void AddY(float y);
    
    const sf::Vector2f& GetPosition() const;
    
  private:
    sf::Vector2f position;
};

#endif