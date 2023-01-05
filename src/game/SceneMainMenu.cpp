#include "SceneMainMenu.hpp"
#include <iostream>
#include <cstdlib>
SceneMainMenu::SceneMainMenu
(WorkingDirectory& workingDir, SceneStateMachine& sceneManager, Window& window)
    :workingDir(workingDir), sceneManager(sceneManager)
{
    this->background.setSize(static_cast<sf::Vector2f>(window.getSize()));
    this->background.setFillColor(sf::Color::Blue);
}

void SceneMainMenu::onDestroy()
{

}

void SceneMainMenu::onCreate()
{

}


void SceneMainMenu::processInput()
{
    this->input.Update();
}

void SceneMainMenu::Update(const float &deltaTime, Window &window)
{
    this->updateMousePosition(window);
}

void SceneMainMenu::LateUpdate(const float &deltaTime)
{

}


void SceneMainMenu::Draw(Window &window)
{
    window.Draw(this->background);
}

void SceneMainMenu::closeScene() {

}

