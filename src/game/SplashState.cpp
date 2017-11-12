#include "SplashState.hpp"

SplashState::SplashState(StateMachine &machine, sf::RenderWindow &window, bool replace) : State(machine, window, replace) {
    this->text = sf::Text("Sufy Studios", *Codex::AcquireFont("Polya.otf"), 200);
    this->fill = sf::Color::Cyan;
    this->outline = sf::Color(47, 79, 79);
    this->text.setOutlineThickness(10.0f);
    this->text.setStyle(sf::Text::Style::Bold);
    this->text.setFillColor(this->fill);
    this->text.setOutlineColor(this->outline);
    sf::FloatRect bounds = this->text.getGlobalBounds();
    this->text.setPosition(WIDTH/2 - bounds.width/2, HEIGHT/2 - bounds.height/2);
}

void SplashState::pause() {}

void SplashState::resume() {}

void SplashState::update(float dt) {
    sf::Event event;
    while (window.pollEvent(event)) this->handleEvents(event);
    if (this->fill.a == 0  and this->outline.a == 0) this->after = std::unique_ptr<PlayState>(new PlayState(this->machine, this->window, true));
    if (this->fill.a > 0) this->fill.a--;
    else this->fill.a = 0;
    if (this->outline.a > 0) this->outline.a--;
    else this->outline.a = 0;
}

void SplashState::render() {
    this->window.clear();
    this->renderText(this->window);
    if (DEBUGGING) this->renderTextBounds(this->window);
    this->window.display();
}

void SplashState::renderText(sf::RenderTarget &rt) {
    this->text.setFillColor(this->fill);
    this->text.setOutlineColor(this->outline);
    rt.draw(this->text);
}

void SplashState::renderTextBounds(sf::RenderTarget &rt) {
    sf::RectangleShape body;
    sf::FloatRect bounds = this->text.getGlobalBounds();
    body.setSize({bounds.width, bounds.height});
    body.setOutlineThickness(1.0f);
    body.setOutlineColor(sf::Color::Green);
    body.setFillColor(sf::Color::Transparent);
    body.setPosition(bounds.left, bounds.top);
    rt.draw(body);
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