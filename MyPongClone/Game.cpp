//
//  Game.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "PaddleAIManager.h"
#include "ResourcePath.hpp"

void Game::checkForPoints(Ball *ball) {
    bool ballOutOfBounds = false;
    if (ball->getBounds()->left < 0) {
        aiScore++;
        std::stringstream sstm;
        sstm << "AI: " << aiScore;
        aiScoreText.setString(sstm.str());
        ballOutOfBounds = true;
    }
    else if (ball->getBounds()->left > 800) {
        playerScore++;
        std::stringstream sstm;
        sstm << "Player: " << playerScore;
        playerScoreText.setString(sstm.str());
        ballOutOfBounds = true;
    }
    
    if (ballOutOfBounds) {
        ball->resetPosition();
    }
}

void Game::initGame() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    if (!uiFont.loadFromFile(resourcePath() + "MunroSmall.ttf")) {
        EXIT_FAILURE;
    }
    
    aiScore = 0;
    playerScore = 0;
    
    Paddle p(10.0f, 300.0f);
    gameObjects.push_back(&p);
    Ball b;
    gameObjects.push_back(&b);
    
    Paddle p2(760.0f, 300.0f);
    p2.setAsAi();
    gameObjects.push_back(&p2);
    
    input = InputManager();
    
    sf::Clock clock = sf::Clock();
    sf::FloatRect intersection;
    sf::Vector2f correction;
    
    playerScoreText.setFont(uiFont);
    aiScoreText.setFont(uiFont);
    
    playerScoreText.setString("Player: 0");
    playerScoreText.setPosition(40, 15);
    playerScoreText.setColor(sf::Color::White);
    playerScoreText.setCharacterSize(22);
    aiScoreText.setString("AI: 0");
    aiScoreText.setPosition(700, 15);
    aiScoreText.setColor(sf::Color::White);
    aiScoreText.setCharacterSize(22);
    
    PaddleAIManager paddleAI;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                else {
                    input.captureKey(event.key.code);
                }
            }
            
            if (event.type == sf::Event::KeyReleased) {
                input.releaseKey(event.key.code);
            }
        }
        
        window.clear();
        
        const float time = clock.getElapsedTime().asSeconds();
        
        for (GameObject* object : gameObjects) {
            object->update(input, time);
        }
        
        b.update(input, time);
        p.update(input, time);
        
        paddleAI.adjustPaddlePosition(b, p2, time);
        p2.update(input, time);
        
        
        runCollisionChecks(p, b, intersection, correction);
        runCollisionChecks(p2, b, intersection, correction);
        
        checkForPoints(&b);
        
        clock.restart();
        
        for (GameObject* object : gameObjects) {
            object->render(window);
        }
        
        window.draw(playerScoreText);
        window.draw(aiScoreText);
        
        // Update the window
        window.display();

    }
}

void Game::runCollisionChecks(Paddle &p, Ball &b, sf::FloatRect &intersection, sf::Vector2f &correction) {
    sf::FloatRect *paddleBounds = p.getBounds();
    sf::FloatRect *ballBounds = b.getBounds();
    if (paddleBounds->intersects(*ballBounds, intersection)) {
        if (intersection.width > intersection.height) {
            if ((ballBounds->top < paddleBounds->top && b.getSpeed()->y > 0) || (ballBounds->top > paddleBounds->top && b.getSpeed()->y < 0)) {
                b.changeYDirection();
            }
        }
        else {
            if ((ballBounds->left < paddleBounds->left && b.getSpeed()->x > 0) || (ballBounds->left > paddleBounds->left && b.getSpeed()->x < 0)) {
                b.changeXDirection();
            }
        }
        
        collisionManager.correctOverlap(ballBounds, &intersection, b.getSpeed(), &correction);
    }
}