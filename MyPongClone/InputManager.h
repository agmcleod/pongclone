//
//  InputManager.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__InputManager__
#define __MyPongClone__InputManager__

#include <stdio.h>
#include <map>
#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager() {
        map.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Key::W, "up"));
        map.insert(std::pair<sf::Keyboard::Key, std::string>(sf::Keyboard::Key::S, "down"));
    }
private:
    std::map<sf::Keyboard::Key, std::string> map;
};

#endif /* defined(__MyPongClone__InputManager__) */
