//
//  Game.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "Renderer.h"
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "ResourcePath.hpp"

void Game::initGame() {
    srand(time(0));
    sf::Window window(sf::VideoMode(800, 600), "SFML window");
    
    if (!uiFont.loadFromFile(resourcePath() + "MunroSmall.ttf")) {
        EXIT_FAILURE;
    }
    
    sf::Clock clock = sf::Clock();
    gameScreen.setUIFont(&uiFont);
    
    titleScreen.setUIFont(&uiFont);
    titleScreen.start();
    
    currentScreen = &gameScreen;
    
    input = InputManager();
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    Renderer renderer(800.0f, 600.0f);
    
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
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        const float time = clock.getElapsedTime().asSeconds();
        
        currentScreen->update(input, time);
        
        clock.restart();
        
        if(currentScreen == &titleScreen && titleScreen.isButtonPressed()) {
            currentScreen = &gameScreen;
            gameScreen.start();
        }
        else if(currentScreen == &gameScreen && gameScreen.isGameOver()) {
            titleScreen.reset();
            currentScreen = &titleScreen;
        }
        
        // Update the window
        window.display();

    }
}
