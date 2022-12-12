#include "Window.hpp"

Window::Window(const std::string& windowName) : window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
}

void Window::Update()
{
    sf::Event event;
    if (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Window::BeginDraw()
{
    window.clear(sf::Color::White);
}

void Window::Draw(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::EndDraw()
{
    window.display();
}

bool Window::IsOpen() const
{
    return window.isOpen();
}


sf::Vector2u Window::getCentre() const
{
    sf::Vector2u size = window.getSize();
    
    return sf::Vector2u(size.x / 2, size.y / 2);
}

sf::Vector2u Window::getSize() const {
    return this->window.getSize();
}
