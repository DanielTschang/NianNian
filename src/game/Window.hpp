#ifndef Window_hpp
#define Window_hpp

#include <SFML/Graphics.hpp>
#include "WorkingDirectory.hpp"

class Window
{
public:
    Window();
    void initVariables();
    void Update();
    
    void BeginDraw();
    void Draw(const sf::Drawable& drawable);
    void EndDraw();

    sf::Vector2u getCentre() const;
    sf::Vector2u getSize() const;
    
    bool IsOpen() const;
    void closeWindow();

    void setView(const sf::View& view);
    const sf::View& getView() const;
    
private:
    sf::RenderWindow window;

    //settings variables
    std::string windowTitle;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings windowSettings;
    bool fullScreen;
    bool verticalSyncEnabled;
    unsigned int antialiasingLevel;
    unsigned int framerateLimit;
    sf::VideoMode windowBounds;

public:
    const sf::RenderWindow &getWindow() const;

    void setWindow(const sf::RenderWindow &window);
};


#endif