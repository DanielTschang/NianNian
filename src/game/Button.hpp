#ifndef NIANNIAN_BUTTON_HPP
#define NIANNIAN_BUTTON_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Window.hpp"
#include "Scene.hpp"

enum e_buttonStates{ButtonIdle = 0, ButtonHover, ButtonActive};
class Button {
protected:
    bool buttonPressed;
    bool buttonHovered;


    short unsigned buttonState;

    sf::RectangleShape buttonShape;
    sf::Font* textFont;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;



public:
    Button(float x, float y, float width, float height, std::string text, sf::Font* font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    //Functions
    void Draw(Window &window);
    void Update(sf::Vector2f& vector2f);

    void getButtonState(sf::Vector2f& mousePosition);
    //Accessors
    const bool isPressed() const;

};


#endif //NIANNIAN_BUTTON_HPP
