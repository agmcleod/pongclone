//
//  Game.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__Game__
#define __MyPongClone__Game__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "InputManager.h"

class GameObject;

class Game {
public:
    void initGame();
private:
    std::vector<GameObject *> gameObjects;
    InputManager input;
};

#endif /* defined(__MyPongClone__Game__) */
