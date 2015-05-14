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

void TitleScreen::render(Renderer &renderer) {
    renderer.text("Press Enter to Start", 280, 300, 0.8f, glm::vec3(1.0f, 1.0f, 1.0f));
}

void TitleScreen::reset() {
    buttonPressed = false;
}

void TitleScreen::start() {
    buttonPressed = false;
}

void TitleScreen::update(InputManager &input, float time) {
    if (input.isActionPressed("action")) {
        buttonPressed = true;
    }
}