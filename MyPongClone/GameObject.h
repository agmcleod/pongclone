//
//  GameObject.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__GameObject__
#define __MyPongClone__GameObject__

#include <stdio.h>
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual void render(sf::RenderWindow &window);
    virtual void update();
};

#endif /* defined(__MyPongClone__GameObject__) */
