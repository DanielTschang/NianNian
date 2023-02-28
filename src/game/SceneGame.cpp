#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator,
                     Window& window, SceneStateMachine& sceneManager, Input &input)
                     : Scene(window, sceneManager, input), workingDir(workingDir), textureAllocator(textureAllocator)
{
    this->isClose = false;
}


void SceneGame::onCreate()
{
    sharedContext.input = &this->input;
    sharedContext.workingDir = &this->workingDir;
    sharedContext.objects = &this->objects;
    sharedContext.window = &this->window;
    sharedContext.textureAllocator = &this->textureAllocator;
//    sharedContext.fontAllocator = &this->fontAllocator;

    this->createPlayer();
}

void SceneGame::createPlayer() {
    std::shared_ptr<Player> player = std::make_shared<Player>(&this->sharedContext);
    objects.Add(player);
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
    this->map.Draw(window);
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

