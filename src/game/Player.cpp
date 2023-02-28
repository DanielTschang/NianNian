#include "Player.hpp"


Player::Player(SharedContext* context)
        :Object(context)
{
    this->initVariables();
    this->initComponents();

}

Player::~Player() {}


void Player::initVariables() {

}

void Player::initComponents() {
    auto sprite = this->AddComponent<C_Sprite>();
    sprite->SetTextureAllocator(this->context->textureAllocator);


    auto movement = this->AddComponent<C_Movement>();
    this->AddComponent<C_Velocity>();
    this->AddComponent<C_Direction>();
    this->AddComponent<C_MovementAnimation>();
    this->initHitBot();
    this->initAnimations();
    this->AddComponent<C_CameraView>();


    auto movementDash = this->AddComponent<C_DashMovement>();
    movementDash->setCooldown(0.5);
    movementDash->setDashDistant(50.f);

    auto basicAttack = this->AddComponent<C_BasicAttackAnimation>();



}

void Player::initAnimations() {
    // Add animation component:
    animation = this->AddComponent<C_Animation>();
    const int frameWidth = 64;
    const int frameHeight = 64;
    const std::vector<FacingDirection> directions{FacingDirection::Up, FacingDirection::Left, FacingDirection::Down, FacingDirection::Right};

    int playerTextureID;
    playerTextureID = context->textureAllocator->Add(context->workingDir->Get() + "Player.png");
    this->createIdleAnimation(playerTextureID, frameWidth, frameHeight, directions);
    this->createWalkAnimation(playerTextureID, frameWidth, frameHeight, directions);
    this->createAttackAnimation(playerTextureID, frameWidth, frameHeight, directions);

}

void Player::initHitBot()
{
    const float offsetX = 15;
    const float offsetY = 12;
    const float width = 33.f;
    const float height = 50.f;
    auto hitbox = this->AddComponent<C_Hitbox>();
    hitbox->setOffset(offsetX, offsetY);
    hitbox->setSize(width, height);
}

void Player::createIdleAnimation(const int &TextureID, const int &frameWidth, const int &frameHeight, const std::vector<FacingDirection> directions) {

    //Create The idle animation
    std::unordered_map<FacingDirection, std::shared_ptr<Animation>, EnumClassHash> idleAnimations;

    const bool idleAnimationLooped = false;
    const float idleAnimFrameSeconds = 0.2f;
    unsigned int idleYFramePos = 512;

    for (int i = 0; i < 4; i++)
    {
        std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>();
        idleAnimation->AddFrame(TextureID, 0, idleYFramePos, frameWidth, frameHeight, idleAnimFrameSeconds);
        idleAnimations.insert(std::make_pair(directions[i], idleAnimation));

        idleYFramePos += frameHeight;
    }

    animation->AddAnimation(AnimationState::Idle, idleAnimations);
}

void Player::createWalkAnimation(const int &TextureID, const int &frameWidth, const int &frameHeight, const std::vector<FacingDirection> directions) {
    const bool walkAnimationLooped = true;
    const int walkingFrameCount = 9;
    const float delayBetweenWalkingFramesSecs = 0.1f;

    // Create the frames.
    unsigned int walkingYFramePos = 512;

    std::unordered_map<FacingDirection, std::shared_ptr<Animation>, EnumClassHash> walkingAnimations;

    for (int i = 0; i < 4; i++)
    {
        std::shared_ptr<Animation> walkingAnimation = std::make_shared<Animation>();
        walkingAnimation->SetLooped(walkAnimationLooped);
        for (int i = 0; i < walkingFrameCount; i++)
        {
            walkingAnimation->AddFrame(TextureID, i * frameWidth, walkingYFramePos, frameWidth, frameHeight, delayBetweenWalkingFramesSecs);
        }

        walkingAnimations.insert(std::make_pair(directions[i], walkingAnimation));

        walkingYFramePos += frameHeight;
    }

    animation->AddAnimation(AnimationState::Walk, walkingAnimations);
}


void Player::createAttackAnimation(const int &TextureID, const int &frameWidth, const int &frameHeight, const std::vector<FacingDirection> directions) {
    const bool attackAnimationLooped = false;

    const int attackFrameCount = 8;
    const float delayBetweenAttackFrameCountFramesSecs = 0.1f;
    unsigned int attackYFramePos = 256;
    std::unordered_map<FacingDirection, std::shared_ptr<Animation>, EnumClassHash> attackAnimations;
    for (int i = 0; i < 4; i++)
    {
        std::shared_ptr<Animation> attackAnimation = std::make_shared<Animation>();
        attackAnimation->SetLooped(attackAnimationLooped);
        for (int i = 0; i < attackFrameCount; i++)
        {
            attackAnimation->AddFrame(TextureID, i * frameWidth, attackYFramePos, frameWidth, frameHeight, delayBetweenAttackFrameCountFramesSecs);
        }

        attackAnimations.insert(std::make_pair(directions[i], attackAnimation));

        attackYFramePos += frameHeight;
    }

    // Add animation to our Viking.
    animation->AddAnimation(AnimationState::Attack, attackAnimations);
}