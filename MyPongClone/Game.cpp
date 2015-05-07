//
//  Game.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "Game.h"
#include "Paddle.h"

void Game::initGame() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    Paddle p(10.0f, 300.0f);
    gameObjects.push_back(&p);
    
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
            }
        }
        
        window.clear();
        
        
        for (GameObject* object : gameObjects) {
            object->update();
        }
        
        for (GameObject* object : gameObjects) {
            object->render(window);
        }
        
        // Update the window
        window.display();

    }
}