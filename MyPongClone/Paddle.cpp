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