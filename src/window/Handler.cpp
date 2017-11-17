#include "Handler.hpp"

void Handler::update(float dt) {
    for (auto o : this->objects) o->update(dt);
}

void Handler::render(sf::RenderTarget &rt) {
    for (auto o : this->objects) o->render(rt);
}

void Handler::loadLevel(const sf::Image& image) {
    sf::Vector2u dimensions = image.getSize();
    for (int xx = 0; xx < dimensions.x; ++xx) {
        for (int yy = 0; yy < dimensions.y; ++yy) {
            sf::Color color = image.getPixel(xx, yy);
            sf::Color white = {255, 255, 255};
            sf::Color blue = {0, 0, 255};
            if (color == white) this->addObject(std::make_shared<Block>(xx*32, yy*32, true));
            if (color == blue) this->addObject(std::make_shared<Player>(xx*32, yy*32, this));
        }
    }
}

void Handler::addObject(std::shared_ptr<GameObject> object) {
    this->objects.emplace_back(object);
}

void Handler::removeObject(std::shared_ptr<GameObject> object) {
    this->objects.remove(object);
}