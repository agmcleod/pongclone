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

class GameObject;

class Game {
public:
    void initGame();
    void runCollisionChecks(Paddle &p, Paddle &p2, Ball &b, sf::FloatRect &intersection, sf::Vector2f &correction);
private:
    void checkForPoints(Ball *ball);
    std::vector<GameObject *> gameObjects;
    InputManager input;
    int aiScore;
    int playerScore;
    sf::Text playerScoreText;
    sf::Text aiScoreText;
    sf::Font uiFont;

    CollisionManager collisionManager;
};

#endif /* defined(__MyPongClone__Game__) */
