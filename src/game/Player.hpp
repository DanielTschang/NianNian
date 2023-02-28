//
// Created by danchang11 on 2023/2/13.
//

#ifndef NIANNIAN_PLAYER_HPP
#define NIANNIAN_PLAYER_HPP

#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_Movement.hpp"
#include "C_DashMovement.hpp"
#include "C_Hitbox.hpp"
#include "C_BasicAttackAnimation.hpp"
#include "C_CameraView.hpp"
#include "Input.hpp"
#include "ResourceAllocator.hpp"
#include "WorkingDirectory.hpp"
#include <vector>
#include "EnumClassHash.hpp"
#include "C_MovementAnimation.hpp"


class Player : public Object {
public:
    Player(SharedContext* context);
    ~Player();
private:
    void initVariables();
    void initComponents();
    void initAnimations();
    void initHitBot();
private:
    std::shared_ptr<C_Animation> animation;

    void createIdleAnimation(const int &TextureID, const int &frameWidth, const int &frameHeight, const std::vector<FacingDirection> directions);
    void createWalkAnimation(const int &TextureID, const int &frameWidth, const int &frameHeight, const std::vector<FacingDirection> directions);
    void createAttackAnimation(const int &TextureID, const int &frameWidth, const int &frameHeight, const std::vector<FacingDirection> directions);

};


#endif //NIANNIAN_PLAYER_HPP
