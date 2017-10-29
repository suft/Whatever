#include "Camera.hpp"

Camera::Camera() {
    this->view = sf::View({width/2, height/2}, {width, height});
}

void Camera::move(std::shared_ptr<GameObject> object) {
    sf::Vector2f center = this->view.getCenter();
    this->view.move(
        (object->getPositionX() - center.x) * 0.2f,
        (object->getPositionY() - center.y) * 0.2f
    );
}

void Camera::render(sf::RenderTarget& rt) {
    rt.setView(this->view);
}