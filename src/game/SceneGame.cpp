#include "SceneGame.hpp"
#include "C_Movement.hpp"
#include <iostream>

SceneGame::SceneGame(WorkingDirectory& workingDir) : workingDir(workingDir)
{
    
}

void SceneGame::onCreate()
{
    player = std::make_shared<Object>();
    
    // Adds a component by calling our previously written template function.
    auto sprite = player->AddComponent<C_Sprite>(); 
    auto movement = player->AddComponent<C_Movement>();
    sprite->Load(workingDir.Get() + "viking.png");
    movement->SetInput(&input); 
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
    player->Update(deltaTime); 
}

void SceneGame::Draw(Window& window)
{
    player->Draw(window);
}

void SceneGame::LateUpdate(float deltaTime)
{
     player->LateUpdate(deltaTime);
}