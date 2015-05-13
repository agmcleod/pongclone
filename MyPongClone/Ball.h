//
//  Ball.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-07.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__Ball__
#define __MyPongClone__Ball__

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Renderer.h"

class Ball : public GameObject {
public:
    Ball() {
        bounds = sf::FloatRect(385, 285, 30, 30);
        m_rect = sf::RectangleShape(sf::Vector2f(bounds.width, bounds.height));
        m_rect.setPosition(bounds.left, bounds.top);
        m_rect.setFillColor(sf::Color::White);
        m_speed = sf::Vector2f();
        resetVelocity();
        resetMoveCountdown();
    }
    
    void changeXDirection();
    void changeYDirection();
    sf::FloatRect * getBounds();
    sf::Vector2f * getSpeed();
    void move(sf::Vector2f *moveBy);
    void resetPosition();
    void resetMoveCountdown();
    void resetVelocity();
    
    virtual void render(Renderer &renderer);
    virtual void update(InputManager &im, const float time);
private:
    sf::FloatRect bounds;
    sf::RectangleShape m_rect;
    sf::Vector2f m_speed;
    float moveCountdown;
};

#endif /* defined(__MyPongClone__Ball__) */
