#include "Window.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Window::Window()
{
    this->initVariables();
    //create Window with configs
    if(this->fullScreen)
        this->window.create(windowBounds, windowTitle,sf::Style::Fullscreen, windowSettings);
    else
        this->window.create(windowBounds, windowTitle,sf::Style::Titlebar | sf::Style::Close, windowSettings);
    this->window.setVerticalSyncEnabled(verticalSyncEnabled);
    this->window.setFramerateLimit(framerateLimit);
}

void Window::initVariables()
{
    //load the config file
    std::ifstream ifs(WorkingDirectory::GetWindowConfig() + "Window.ini");

    //init the variables
    this->windowTitle = "default window name";
    this->videoModes = sf::VideoMode::getFullscreenModes();
    this->windowBounds = sf::VideoMode::getDesktopMode();
    this->framerateLimit = 120;
    this->verticalSyncEnabled = true;
    this->fullScreen = false;
    this->antialiasingLevel = 0;

    if(ifs.is_open())
    {
        std::getline(ifs, this->windowTitle);
        ifs >> this->windowBounds.width >> this->windowBounds.height;
        ifs >> this->fullScreen;
        ifs >> this->framerateLimit;
        ifs >> this->verticalSyncEnabled;
        ifs >> this->antialiasingLevel;
    }
    ifs.close();
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

void Window::closeWindow() {
    this->window.close();
}

const sf::RenderWindow &Window::getWindow() const {
    return window;
}

const sf::View& Window::getView() const
{
    return window.getView();
}

void Window::setView(const sf::View& view)
{
    window.setView(view);
}
