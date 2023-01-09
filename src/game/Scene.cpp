#include "Scene.hpp"

Scene::Scene(Window& window, SceneStateMachine& sceneManager) : isClose(false),window(window), sceneManager(sceneManager)
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

