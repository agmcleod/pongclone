//
//  GameScreen.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-10.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "GameScreen.h"
#include <sstream>

void GameScreen::checkForPoints(Ball *ball) {
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

bool GameScreen::isGameOver() {
    return aiScore >= 10 || playerScore >= 10;
}

void GameScreen::render(Renderer &renderer) {
    for (GameObject* object : gameObjects) {
        object->render(renderer);
        renderer.flush();
    }
    // ai.render(Renderer &renderer);
    // window.draw(playerScoreText);
    // window.draw(aiScoreText);
}

void GameScreen::runCollisionChecks(Paddle &p, Ball &b, sf::FloatRect &intersection, sf::Vector2f &correction) {
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

void GameScreen::setUIFont(sf::Font *f) {
    uiFont = f;
}

void GameScreen::start() {
    aiScore = 0;
    playerScore = 0;
    
    gameObjects.clear();
    
    gameObjects.push_back(&player);
    gameObjects.push_back(&ball);
    ai.setAsAi();
    
    sf::FloatRect intersection;
    sf::Vector2f correction;
    
    playerScoreText.setString("Player: 0");
    playerScoreText.setPosition(40, 15);
    playerScoreText.setColor(sf::Color::White);
    playerScoreText.setCharacterSize(22);
    aiScoreText.setString("AI: 0");
    aiScoreText.setPosition(700, 15);
    aiScoreText.setColor(sf::Color::White);
    aiScoreText.setCharacterSize(22);
    
    playerScoreText.setFont(*uiFont);
    aiScoreText.setFont(*uiFont);
}

void GameScreen::update(InputManager &input, float time) {
    for (GameObject* object : gameObjects) {
        object->update(input, time);
    }
    
    //paddleAI.adjustPaddlePosition(ball, ai, time);
    //ai.update(input, time);
    
    sf::Vector2f correction(0, 0);
    sf::FloatRect intersection;
    
    runCollisionChecks(player, ball, intersection, correction);
    runCollisionChecks(ai, ball, intersection, correction);
    
    checkForPoints(&ball);
}