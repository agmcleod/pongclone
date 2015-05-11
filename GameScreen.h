//
//  GameScreen.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-10.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__GameScreen__
#define __MyPongClone__GameScreen__

#include <stdio.h>
#include <vector>
#include "Ball.h"
#include "Paddle.h"
#include "Screen.h"
#include "CollisionManager.h"
#include "PaddleAIManager.h"

class GameScreen : public Screen {
public:
    GameScreen() : player(Paddle(10.0f, 300.0f)), ai(Paddle(760.0f, 300.0f)), ball(Ball()) {}
    void runCollisionChecks(Paddle &p, Ball &b, sf::FloatRect &intersection, sf::Vector2f &correction);
    void checkForPoints(Ball *ball);
    void setUIFont(sf::Font *uiFont);
    
    virtual void render(sf::RenderWindow &window);
    virtual void start();
    virtual void update(InputManager &input, float time);
private:
    int aiScore;
    Paddle ai;
    Ball ball;
    sf::Text aiScoreText;
    std::vector<GameObject *> gameObjects;
    int playerScore;
    sf::Font *uiFont;
    Paddle player;
    sf::Text playerScoreText;
    PaddleAIManager paddleAI;
    CollisionManager collisionManager;
};

#endif /* defined(__MyPongClone__GameScreen__) */
