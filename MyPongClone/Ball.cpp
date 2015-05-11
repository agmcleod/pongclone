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

sf::Vector2f * Ball::getSpeed() {
    return &m_speed;
}

void Ball::move(sf::Vector2f *moveBy) {
    bounds.left += moveBy->x;
    bounds.top += moveBy->y;
    m_rect.setPosition(bounds.left, bounds.top);
}

void Ball::render(sf::RenderWindow &window) {
    window.draw(m_rect);
}

void Ball::resetMoveCountdown() {
    moveCountdown = 0.8f;
}

void Ball::resetPosition() {
    bounds.left = 385;
    bounds.top = 285;
    changeXDirection();
    m_rect.setPosition(bounds.left, bounds.top);
    resetMoveCountdown();
    resetVelocity();
}

void Ball::resetVelocity() {
    const float v = 450;
    int randomval = rand() % 2;
    if (randomval == 0) {
        m_speed.x = v;
    }
    else if(randomval == 1) {
        m_speed.x = -v;
    }
    
    randomval = rand() % 2;
    if (randomval == 0) {
        m_speed.y = v;
    }
    else if(randomval == 1) {
        m_speed.y = -v;
    }
}

void Ball::update(InputManager &im, const float time) {
    if (moveCountdown > 0.0f) {
        moveCountdown -= time;
    }
    else {
        bounds.left += m_speed.x * time;
        bounds.top += m_speed.y * time;
        
        if (bounds.top < 0) {
            bounds.top = 1;
            changeYDirection();
        }
        else if (bounds.top > 600 - bounds.height) {
            bounds.top = 600 - bounds.height - 1;
            changeYDirection();
        }
        m_rect.setPosition(bounds.left, bounds.top);
    }
}