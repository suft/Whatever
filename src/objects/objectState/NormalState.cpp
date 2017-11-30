//
// Created by Elman Chao on 2017-11-23.
//

#include "NormalState.hpp"

void NormalState::handleEvents(const sf::Event &event) {
    switch(event.type) {
        case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::LShift) {

            } else if(event.key.code == sf::Keyboard::F) {
                this->afterFound = true;
                this->after = 
            }
            break;
        default:
            break;
    }
}
