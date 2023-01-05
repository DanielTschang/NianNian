#include "Scene.hpp"


Scene::Scene() {

}

void Scene::updateMousePosition(Window &window) {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(window.getWindow());
    this->mousePosView = window.getWindow().mapPixelToCoords(sf::Mouse::getPosition(window.getWindow()));
}
