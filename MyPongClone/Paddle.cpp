//
//  Paddle.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "Paddle.h"

sf::FloatRect * Paddle::getBounds() {
    return &bounds;
}

void Paddle::moveDown(float time) {
    bounds.top += m_speed * time;
}

void Paddle::moveUp(float time) {
    bounds.top -= m_speed * time;
}

void Paddle::render(sf::RenderWindow &window) {
    window.draw(m_rect);
}

void Paddle::setAsAi() {
    isAi = true;
}

void Paddle::update(InputManager &im, const float time) {
    if (!isAi) {
        if (im.isActionPressed("up")) {
            moveUp(time);
        }
        if (im.isActionPressed("down")) {
            moveDown(time);
        }
    }
    
    if (bounds.top < 0) {
        bounds.top = 0;
    }
    int yLimit = 600 - m_rect.getSize().y;
    if (bounds.top > yLimit) {
        bounds.top = yLimit;
    }
    
    m_rect.setPosition(bounds.left, bounds.top);
}