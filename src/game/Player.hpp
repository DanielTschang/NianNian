//
// Created by danchang11 on 2023/2/13.
//

#ifndef NIANNIAN_PLAYER_HPP
#define NIANNIAN_PLAYER_HPP

#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_Movement.hpp"
#include "C_DashMovement.hpp"
#include "Input.hpp"
#include "ResourceAllocator.hpp"
#include "WorkingDirectory.hpp"


class Player : public Object {
public:
    Player( Input &input, ResourceAllocator<sf::Texture> &textureAllocator, WorkingDirectory &workingDir);
    ~Player();

private:
    void initVariables();
    void initComponents();
    void initAnimations();
private:
    Input &input;
    ResourceAllocator<sf::Texture> &textureAllocator;
    WorkingDirectory &workingDir;

};


#endif //NIANNIAN_PLAYER_HPP
