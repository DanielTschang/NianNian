#pragma once

#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    Window(const std::string& windowName);

    void Update();
    
    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();

    bool IsOpen() const;

private:
    sf::RenderWindow window;

};