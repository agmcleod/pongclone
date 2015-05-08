//
//  CollisionManager.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-07.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__CollisionManager__
#define __MyPongClone__CollisionManager__

#include <stdio.h>
#include <SFML/Graphics.hpp>

class CollisionManager {
public:
    void correctOverlap(sf::FloatRect *rectone, sf::FloatRect *intersection, sf::Vector2f *velocity, sf::Vector2f *correction);
};

#endif /* defined(__MyPongClone__CollisionManager__) */
