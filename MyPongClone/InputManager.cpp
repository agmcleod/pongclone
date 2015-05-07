//
//  InputManager.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-06.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "InputManager.h"

void InputManager::captureKey(sf::Keyboard::Key &key) {
    m_actions[m_map[key]] = true;
}

bool InputManager::isActionPressed(std::string action) {
    return m_actions[action];
}

void InputManager::releaseKey(sf::Keyboard::Key &key) {
    m_actions[m_map[key]] = false;
}