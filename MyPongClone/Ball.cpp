//
//  Ball.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-07.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "Ball.h"

void Ball::changeXDirection() {
    m_speed.x *= -1;
}

void Ball::changeYDirection() {
    m_speed.y *= -1;
}

sf::FloatRect * Ball::getBounds() {
    return &bounds;
}

void Ball::render(sf::RenderWindow &window) {
    window.draw(m_rect);
}

void Ball::update(InputManager &im, float time) {
    bounds.left += m_speed.x * time;
    bounds.top += m_speed.y * time;
    
    if (bounds.top < 0 || bounds.top > 600 - bounds.height) {
        changeYDirection();
    }
    
    m_rect.setPosition(bounds.left, bounds.top);
}