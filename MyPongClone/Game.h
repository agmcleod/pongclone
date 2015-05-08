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
#include <ctime>
#include <cstdlib>
#include "InputManager.h"
#include "Ball.h"

class GameObject;

class Game {
public:
    void initGame();
private:
    void checkForPoints(Ball *ball);
    std::vector<GameObject *> gameObjects;
    InputManager input;
    int aiScore;
    int playerScore;
};

#endif /* defined(__MyPongClone__Game__) */
