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
#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"

class GameObject {
public:
    virtual void render(Renderer &renderer) {};
    virtual void update(InputManager &im, const float time) {};
};

#endif /* defined(__MyPongClone__GameObject__) */
