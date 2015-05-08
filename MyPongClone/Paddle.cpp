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

void Paddle::render(sf::RenderWindow &window) {
    window.draw(m_rect);
}

void Paddle::update(InputManager &im, float time) {
    if (im.isActionPressed("up")) {
        bounds.top -= m_speed * time;
    }
    if (im.isActionPressed("down")) {
        bounds.top += m_speed * time;
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