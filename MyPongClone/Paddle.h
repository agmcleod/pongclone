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
class Game;

#include "GameObject.h"

class Paddle : public GameObject {
public:
    Paddle(float x, float y) {
        m_rect = sf::RectangleShape(sf::Vector2f(30, 60));
        m_rect.setPosition(x, y);
        m_rect.setFillColor(sf::Color::White);
    }
    virtual void render(sf::RenderWindow &window);
    virtual void update();
private:
    sf::RectangleShape m_rect;
};

#endif /* defined(__MyPongClone__Paddle__) */
