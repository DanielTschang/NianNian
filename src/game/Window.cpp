#include "Window.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Window::Window(const std::string& windowName)
{
    //load the config file
    std::ifstream ifs(WorkingDirectory::GetWindowConfig() + "Window.ini");

    //init the variables
    std::string windowTitle = windowName;
    sf::VideoMode windowBounds(800, 600);
    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = true;


    //if config file is loaded then change the variables
    if(ifs.is_open())
    {
        std::getline(ifs, windowTitle);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
    }

    ifs.close();

    this->window.create(windowBounds, windowTitle,sf::Style::Titlebar);
    this->window.setVerticalSyncEnabled(verticalSyncEnabled);
    this->window.setFramerateLimit(framerateLimit);
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
