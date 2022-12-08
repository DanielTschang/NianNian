#include "C_Position.hpp"

C_Position::C_Position(Object* owner): 
    Component(owner), position(0.f, 0.f) { }

void C_Position::SetPosition(const float x, const float y)
{
  position.x = x;
  position.y = y;
}

void C_Position::SetPosition(const sf::Vector2f& pos)
{
  position = pos;
}

void C_Position::AddPosition(const float x, const float y)
{
  position.x += x;
  position.y += y;
}

void C_Position::AddPosition(const sf::Vector2f pos)
{
  position += pos;
}

void C_Position::SetX(float x)
{
  position.x = x;
}

void C_Position::SetY(float y)
{
  position.y = y;
}

void C_Position::AddX(float x)
{
  position.x += x;
}

void C_Position::AddY(float y)
{
  position.y += y;
}

const sf::Vector2f& C_Position::GetPosition() const
{
  return position;
}