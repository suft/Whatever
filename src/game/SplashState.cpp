#include "SplashState.hpp"

SplashState::SplashState(StateMachine &machine, sf::RenderWindow &window, bool replace) : State(machine, window, replace) {
    this->logo = sf::Sprite(*Codex::AcquireTexture("Logo.png"));
    auto local = this->logo.getLocalBounds();
    this->logo.setScale({960 / local.width, 438 / local.height});
    auto global = this->logo.getGlobalBounds();
    this->logo.setPosition({global.width/2, global.height/2 + 100});
    this->background = sf::Color(222, 228, 196);
    this->fader = Fader(
        Direction::In,
        5.0f,
        [](float){},
        std::bind(&SplashState::renderLogo, this, std::placeholders::_1),
        std::bind(&SplashState::swapFader, this)
    );
}

void SplashState::pause() {}

void SplashState::resume() {}

void SplashState::update(float dt) {
    sf::Event event;
    while (window.pollEvent(event)) this->handleEvents(event);
    if (this->fader.getDirection() == Direction::Out and this->fader.isComplete()) {
        this->after = std::unique_ptr<PlayState>(new PlayState(this->machine, this->window, true));
    }
    this->fader.update(dt);
}

void SplashState::render() {
    this->window.clear(this->background);
    this->fader.render(this->window);
    this->window.display();
}

void SplashState::renderLogo(sf::RenderTarget &rt) {
    rt.draw(this->logo);
}

void SplashState::swapFader() {
    if (this->fader.getDirection() == Direction::In and this->fader.isComplete()) {
        this->fader.setDirection(Direction::Out);
        this->fader.setComplete(false);
    }
}

void SplashState::handleEvents(const sf::Event &event) {
    switch (event.type) {
        case sf::Event::Closed:
            this->machine.quit();
            break;
        default:
            break;
    }
}
