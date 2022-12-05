
#include "Window.hpp"

Window::Window(const std::string& windowName) 
	: window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar)
    /*
    *The RenderWindow constructor accepts a sf::VideoMode as a parameter.
    The VideoMode can be use to define the width, height, and depth of the window.
    We are currently creating a non-fullscreen window with a resolution of 800 x 600 pixels
    , although this will change later as we¡¦ll eventually want to make the window full-screen and user adjustable. 
    RenderWindow also accepts a sf::Style parameter; 
    which is an enum and includes options for showing the title bar (an option we are currently using)
    , resizing the window, and whether the window starts fullscreen.
    */
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

void Window::BeginDraw() // 4
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