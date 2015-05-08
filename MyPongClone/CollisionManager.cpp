//
//  CollisionManager.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-07.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "CollisionManager.h"

void CollisionManager::correctOverlap(sf::FloatRect *rectone, sf::FloatRect *intersection, sf::Vector2f *velocity, sf::Vector2f *correction) {
    if (intersection->width > intersection->height) {
        if (velocity->y < 0) {
            correction->y = velocity->y;
        }
        else if (velocity->y > 0) {
            correction->y = -velocity->y;
        }
    }
    else {
        if (velocity->x < 0) {
            correction->x = velocity->x;
        }
        else if (velocity->x > 0) {
            correction->x = -velocity->x;
        }
    }
}