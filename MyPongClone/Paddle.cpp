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

void Paddle::render(Renderer &renderer) {
    GLfloat vertices[28] = {
        //  Position(2) Color(3)     Texcoords(2)
        bounds.left, bounds.top, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // Top-left
        bounds.left + bounds.width, bounds.top, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
        bounds.left + bounds.width, bounds.top + bounds.height, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
        bounds.left, bounds.top + bounds.height, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
    };
    renderer.setupVertices(vertices);
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