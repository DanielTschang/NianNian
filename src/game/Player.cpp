#include "Player.hpp"

Player::Player( Input &input, ResourceAllocator<sf::Texture> &textureAllocator, WorkingDirectory &workingDir)
        :Object(), input(input), workingDir(workingDir), textureAllocator(textureAllocator)
{
    this->initVariables();
    this->initComponents();
    this->initAnimations();
}

Player::~Player() {}


void Player::initVariables() {

}

void Player::initComponents() {
    auto sprite = this->AddComponent<C_Sprite>();
    sprite->SetTextureAllocator(&this->textureAllocator);
    auto movement = this->AddComponent<C_Movement>();
    movement->SetInput(&this->input);
    auto movementDash = this->AddComponent<C_DashMovement>();
    movementDash->SetInput(&this->input);
    movementDash->setCooldown(0.5);
    movementDash->setDashDistant(50.f);
}

void Player::initAnimations() {
    // Add animation component:
    auto animation = this->AddComponent<C_Animation>();

    int vikingTextureID;
    vikingTextureID = textureAllocator.Add(workingDir.Get() + "Viking.png");

    const int frameWidth = 165; //We manually set our sprites width and height for now. In future, we will generate some form of data file (XML, JSON etc.) to do this for us.
    const int frameHeight = 145;

    //Create The idle animation
    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->AddFrame(vikingTextureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->AddAnimation(AnimationState::Idle, idleAnimation);

    // Create the walking animation.
    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float walkAnimFrameSeconds = 0.15f;

    // Create the frames.
    walkAnimation->AddFrame(vikingTextureID, 600, 290,
                            frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 800, 290,
                            frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 0, 435,
                            frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 200, 435,
                            frameWidth, frameHeight,walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 400, 435,
                            frameWidth, frameHeight, walkAnimFrameSeconds);

    // Add animation to our Viking.
    animation->AddAnimation(AnimationState::Walk, walkAnimation);
}
