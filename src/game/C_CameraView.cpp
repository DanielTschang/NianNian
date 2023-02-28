#include "C_CameraView.hpp"

#include "Object.hpp"

C_CameraView::C_CameraView(Object* owner) : Component(owner) { }

void C_CameraView::LateUpdate(const float &deltaTime)
{
    sf::View view = owner->context->window->getView();

    const sf::Vector2f& targetPos = owner->position->getPosition();
    view.setCenter(targetPos.x, targetPos.y);

    owner->context->window->setView(view);
}
