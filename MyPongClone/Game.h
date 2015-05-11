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
#include "Paddle.h"
#include "Ball.h"
#include "CollisionManager.h"
#include "GameScreen.h"

class GameObject;

class Game {
public:
    Game() : gameScreen(GameScreen()) {}
    void initGame();
private:
    InputManager input;
    sf::Font uiFont;
    GameScreen gameScreen;
    
};

#endif /* defined(__MyPongClone__Game__) */
