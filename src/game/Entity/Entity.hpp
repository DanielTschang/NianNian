#ifndef NIANNIAN_ENTITY_HPP
#define NIANNIAN_ENTITY_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "../Window.hpp"

class Entity {
private:
    void initVariables();
protected:
    sf::Texture* texture;
    sf::Sprite sprite;
    float movementSpeed;
public:
    Entity();
    virtual ~Entity();

    //Components
    void createSprite(sf::Texture *texture);
    //Functions
    virtual void move(const float& deltaTime, const float x , const float y);

//    virtual void processInput(const float& deltaTime);

    virtual void Update(const float& deltaTime);
    virtual void LateUpdate(const float& deltaTime);
    virtual void Draw(Window& window);
};


#endif //NIANNIAN_ENTITY_HPP
