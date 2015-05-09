//
//  Paddle.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__Paddle__
#define __MyPongClone__Paddle__

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Paddle : public GameObject {
public:
    Paddle(float x, float y) {
        bounds = sf::FloatRect(x, y, 30, 60);
        m_rect = sf::RectangleShape(sf::Vector2f(bounds.width, bounds.height));
        m_rect.setPosition(bounds.left, bounds.top);
        m_rect.setFillColor(sf::Color::White);
        m_speed = 400.0f;
    }
    sf::FloatRect * getBounds();
    virtual void render(sf::RenderWindow &window);
    void setAsAi();
    virtual void update(InputManager &im, float time);
private:
    sf::FloatRect bounds;
    sf::RectangleShape m_rect;
    float m_speed;
    bool isAi;
};

#endif /* defined(__MyPongClone__Paddle__) */
