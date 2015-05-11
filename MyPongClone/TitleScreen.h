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

class TitleScreen : public Screen {
public:
    void setUIFont(sf::Font *uiFont);
    bool isButtonPressed();
    virtual void render(sf::RenderWindow &window);
    virtual void start();
    virtual void update(InputManager &input, float time);
private:
    bool buttonPressed;
    sf::Text startText;
    sf::Font *uiFont;
};

#endif /* defined(__MyPongClone__TitleScreen__) */
