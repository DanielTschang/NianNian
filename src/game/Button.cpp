//
// Created by danchang11 on 2023/1/5.
//

#include "Button.hpp"

Button::Button(float x, float y, float width, float height, std::string text, sf::Font *font, sf::Color idleColor,
               sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = e_buttonStates::ButtonIdle;

    this->buttonShape.setSize(sf::Vector2f(width,height));
    this->buttonShape.setPosition(sf::Vector2f(x,y));
    this->textFont = font;
    this->text.setFont(*this->textFont);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->buttonShape.setFillColor(this->idleColor);
    this->text.setPosition(
            this->buttonShape.getPosition().x + this->buttonShape.getGlobalBounds().width/2.f - this->text.getGlobalBounds().width /2.f,
            this->buttonShape.getPosition().y + this->buttonShape.getGlobalBounds().height/2.f - this->text.getGlobalBounds().height /2.f
    );
}

Button::~Button() {

}



//Functions


void Button::Draw(Window &window) {
    window.Draw(this->buttonShape);
    window.Draw(this->text);
}

void Button::getButtonState(sf::Vector2f& mousePosition) {
    /*
     * update for hover and active
     */

    //init button is idle
    this->buttonState = e_buttonStates::ButtonIdle;

    //button is hovered
    if (this->buttonShape.getGlobalBounds().contains(mousePosition)) {
        this->buttonState = e_buttonStates::ButtonHover;

        //button is Pressed / Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = e_buttonStates::ButtonActive;
        }
    }

    switch (this->buttonState)
    {
        case e_buttonStates::ButtonIdle:
            this->buttonShape.setFillColor(this->idleColor);
            break;
        case e_buttonStates::ButtonHover:
            this->buttonShape.setFillColor(this->hoverColor);
            break;
        case e_buttonStates::ButtonActive:
            this->buttonShape.setFillColor(this->activeColor);
            break;
        default:
            this->buttonShape.setFillColor(this->idleColor);
            break;
    }
}

void Button::Update(sf::Vector2f& vector2float) {
    this->getButtonState(vector2float);
}

const bool Button::isPressed() const {
    if(this->buttonState == e_buttonStates::ButtonActive)
    {
        return true;
    }
    return false;
}


