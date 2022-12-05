#ifndef Window_h
#define Window_h

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

    sf::Vector2u getCentre() const;
    
    bool IsOpen() const;
    
private:
    sf::RenderWindow window;
};

#endif /* Window_hpp */
