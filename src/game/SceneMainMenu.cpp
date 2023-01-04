#include "SceneMainMenu.hpp"
#include <iostream>
SceneMainMenu::SceneMainMenu
(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window)
    :workingDir(workingDir), sceneManager(sceneManager), window(window)
{
    this->background.setSize(static_cast<sf::Vector2f>(this->window.getSize()));
    this->background.setFillColor(sf::Color::Magenta);
}

void SceneMainMenu::onDestroy()
{

}

void SceneMainMenu::onCreate()
{

}


void SceneMainMenu::processInput()
{
    input.Update();
}

void SceneMainMenu::Update(const float &deltaTime)
{
    if(input.IsKeyPressed(Input::KEY::LEFT))
    {

    }
    if(input.IsKeyPressed(Input::KEY::RIGHT))
    {

    }
    if(input.IsKeyPressed(Input::KEY::UP))
    {

    }
    if(input.IsKeyPressed(Input::KEY::DOWN))
    {

    }
}

void SceneMainMenu::LateUpdate(const float &deltaTime)
{

}

void SceneMainMenu::Draw(Window &window)
{
    window.Draw(this->background);
}

