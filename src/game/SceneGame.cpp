#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, ResourceAllocator<sf::Texture>& textureAllocator,
                     Window& window, SceneStateMachine& sceneManager, Input &input)
                     : Scene(window, sceneManager, input), workingDir(workingDir), textureAllocator(textureAllocator), mapParser(textureAllocator)
{
    this->isClose = false;
}


void SceneGame::onCreate()
{
    std::shared_ptr<Player> player = std::make_shared<Player>(input,this->textureAllocator, workingDir);
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
