//
//  Game.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include <iostream>
#include <ctime>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "ResourcePath.hpp"

void Game::initGame() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    if (!uiFont.loadFromFile(resourcePath() + "MunroSmall.ttf")) {
        EXIT_FAILURE;
    }
    
    sf::Clock clock = sf::Clock();
    gameScreen.setUIFont(&uiFont);
    gameScreen.start();
    
    titleScreen.setUIFont(&uiFont);
    titleScreen.start();
    
    currentScreen = &titleScreen;
    
    input = InputManager();
    
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
        
        currentScreen->update(input, time);
        
        clock.restart();
        
        currentScreen->render(window);
        
        if(currentScreen == &titleScreen && titleScreen.isButtonPressed()) {
            currentScreen = &gameScreen;
        }
        
        // Update the window
        window.display();

    }
}
