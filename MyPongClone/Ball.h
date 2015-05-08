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


class Ball : public GameObject {
public:
    Ball() {
        int randomval = rand() % 2;
        bounds = sf::FloatRect(385, 285, 30, 30);
        m_rect = sf::RectangleShape(sf::Vector2f(bounds.width, bounds.height));
        m_rect.setPosition(bounds.left, bounds.top);
        m_rect.setFillColor(sf::Color::White);
        m_speed = sf::Vector2f();
        const float v = 400;
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
    
    void changeXDirection();
    void changeYDirection();
    sf::FloatRect * getBounds();
    virtual void render(sf::RenderWindow &window);
    virtual void update(InputManager &im, float time);
private:
    sf::FloatRect bounds;
    sf::RectangleShape m_rect;
    sf::Vector2f m_speed;
};

#endif /* defined(__MyPongClone__Ball__) */
