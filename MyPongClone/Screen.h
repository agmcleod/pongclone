//
//  Screen.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-10.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__Screen__
#define __MyPongClone__Screen__

#include <stdio.h>
#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"

class Screen {
public:
    virtual void render(Renderer &renderer) {};
    virtual void start() {};
    virtual void update(InputManager &input, float time) {};
};

#endif /* defined(__MyPongClone__Screen__) */
