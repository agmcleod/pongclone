//
//  Game.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "CollisionManager.h"

void Game::initGame() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    Paddle p(10.0f, 300.0f);
    gameObjects.push_back(&p);
    Ball b;
    gameObjects.push_back(&b);
    
    input = InputManager();
    
    sf::Clock clock = sf::Clock();
    sf::FloatRect intersection;
    sf::Vector2f correction;
    
    CollisionManager collisionManger;
    
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
        
        sf::FloatRect *paddleBounds = p.getBounds();
        sf::FloatRect *ballBounds = b.getBounds();
        
        if (paddleBounds->intersects(*ballBounds, intersection)) {
            if (intersection.width > intersection.height) {
                b.changeYDirection();
            }
            else {
                b.changeXDirection();
            }
            
            collisionManger.correctOverlap(ballBounds, &intersection, b.getSpeed(), &correction);
            
        }
        
        clock.restart();
        
        for (GameObject* object : gameObjects) {
            object->render(window);
        }
        
        // Update the window
        window.display();

    }
}