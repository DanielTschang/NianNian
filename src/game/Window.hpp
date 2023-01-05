#ifndef Window_hpp
#define Window_hpp

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"

class Window
{
public:
    Window();
    Window(const std::string& windowName);
    
    void Update();
    
    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();

    sf::Vector2u getCentre() const;
    sf::Vector2u getSize() const;
    
    bool IsOpen() const;
    void closeWindow();
    
private:
    sf::RenderWindow window;
public:
    const sf::RenderWindow &getWindow() const;

    void setWindow(const sf::RenderWindow &window);
};


#endif