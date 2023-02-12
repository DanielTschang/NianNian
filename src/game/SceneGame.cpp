#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator,
                     Window& window, SceneStateMachine& sceneManager)
                     : Scene(window, sceneManager), workingDir(workingDir), textureAllocator(textureAllocator), mapParser(textureAllocator)
{
    this->isClose = false;
}


void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();

    auto sprite = player->AddComponent<C_Sprite>();
    sprite->SetTextureAllocator(&textureAllocator);
    // We’ve removed the line to set the viking sprite here.
    //The animation component will now be responsible for
    //updating the sprite.

    auto movement = player->AddComponent<C_Movement>();
    movement->SetInput(&this->input);

    auto movementDash = player->AddComponent<C_DashMovement>();
    movementDash->SetInput(&this->input);
    movementDash->setCooldown(0.5);
    movementDash->setDashDistant(50.f);

    // Add our new animation component:
    auto animation = player->AddComponent<C_Animation>();

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

    objects.Add(player);

//    sf::Vector2i mapOffset(0, 0);
//    std::vector<std::shared_ptr<Object>> levelTiles
//            = mapParser.Parse(workingDir.Get() + "Test Map 1.tmx", mapOffset);
//
//    objects.Add(levelTiles);
}

void SceneGame::onDestroy()
{
    
}

void SceneGame::processInput()
{
    input.Update();
}

void SceneGame::Update(const float& deltaTime)
{
    objects.ProcessRemovals();
    objects.ProcessNewObjects();
    objects.Update(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    this->objects.Draw(window);
}

void SceneGame::LateUpdate(const float& deltaTime)
{
     objects.LateUpdate(deltaTime);
}

void SceneGame::closeScene() {
    if(this->input.IsKeyPressed(Input::KEY::ESC))
    {
        this->isClose = true;
    }
}
