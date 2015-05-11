//
//  TitleScreen.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-10.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "TitleScreen.h"

bool TitleScreen::isButtonPressed() {
    return buttonPressed;
}

void TitleScreen::render(sf::RenderWindow &window) {
    window.draw(startText);
}

void TitleScreen::reset() {
    buttonPressed = false;
}

void TitleScreen::setUIFont(sf::Font *f) {
    uiFont = f;
}

void TitleScreen::start() {
    startText.setString("Press Enter to Start");
    startText.setColor(sf::Color::White);
    startText.setCharacterSize(30);
    startText.setPosition(280, 300);
    startText.setFont(*uiFont);
    buttonPressed = false;
}

void TitleScreen::update(InputManager &input, float time) {
    if (input.isActionPressed("action")) {
        buttonPressed = true;
    }
}