#include "Scene.hpp"

Scene::Scene(Window& window, SceneStateMachine& sceneManager, Input &input) : isClose(false),window(window), sceneManager(sceneManager), input(input)
{
}

void Scene::updateMousePosition(Window &window) {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(window.getWindow());
    this->mousePosView = window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(window.getWindow()));
}

void Scene::LateUpdate(const float &deltaTime) {
    if(this->isClose)
        window.closeWindow();
}

