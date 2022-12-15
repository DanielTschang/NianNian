#include "SceneGame.hpp"

SceneGame::SceneGame(WorkingDirectory& workingDir, Window& window) : workingDir(workingDir), window(window){}
void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();
    
    // Adds a component by calling our previously written template function.
    auto sprite = player->AddComponent<C_Sprite>(); 
    auto movement = player->AddComponent<C_Movement>();
    sprite->Load(workingDir.Get() + "viking.png");
    movement->SetInput(&input);

    objects.Add(player); // it will only add to newobject but wouldn't update.
}

void SceneGame::onDestroy()
{
    
}

void SceneGame::processInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    objects.ProcessRemovals();
    objects.ProcessNewObjects();
    objects.Update(deltaTime);
}

void SceneGame::Draw(Window& window)
{
    objects.Draw(window);
}

void SceneGame::LateUpdate(float deltaTime)
{
     objects.LateUpdate(deltaTime);
}