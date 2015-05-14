//
//  TitleScreen.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-10.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__TitleScreen__
#define __MyPongClone__TitleScreen__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "Renderer.h"

class TitleScreen : public Screen {
public:
    bool isButtonPressed();
    void reset();
    virtual void render(Renderer &renderer);
    virtual void start();
    virtual void update(InputManager &input, float time);
private:
    bool buttonPressed;
};

#endif /* defined(__MyPongClone__TitleScreen__) */
