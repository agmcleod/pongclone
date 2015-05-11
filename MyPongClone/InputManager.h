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
#include <utility>
#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager() {
        m_map.insert(std::make_pair(sf::Keyboard::Key::W, "up"));
        m_map.insert(std::make_pair(sf::Keyboard::Key::S, "down"));
        m_map.insert(std::make_pair(sf::Keyboard::Key::Return, "action"));
        
        m_actions.insert(std::make_pair("up", false));
        m_actions.insert(std::make_pair("down", false));
        m_actions.insert(std::make_pair("action", false));
    }
    
    void captureKey(sf::Keyboard::Key &key);
    void releaseKey(sf::Keyboard::Key &key);
    
    bool isActionPressed(std::string action);
private:
    std::map<sf::Keyboard::Key, std::string> m_map;
    std::map<std::string, bool> m_actions;
};

#endif /* defined(__MyPongClone__InputManager__) */
