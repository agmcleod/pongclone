//
//  Paddle.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "Paddle.h"

void Paddle::render(sf::RenderWindow &window) {
    window.draw(m_rect);
}

void Paddle::update(InputManager &im, float time) {
    if (im.isActionPressed("up")) {
        m_rect.move(0, -m_speed * time);
    }
    if (im.isActionPressed("down")) {
        m_rect.move(0, m_speed * time);
    }
}