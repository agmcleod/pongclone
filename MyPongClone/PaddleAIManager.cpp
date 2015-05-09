//
//  PaddleAIManager.cpp
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-09.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#include "PaddleAIManager.h"

void PaddleAIManager::adjustPaddlePosition(Ball &b, Paddle &p, float time) {
    if (b.getBounds()->top < p.getBounds()->top - 10) {
        p.moveUp(time);
    }
    else if (b.getBounds()->top + b.getBounds()->height > p.getBounds()->top + b.getBounds()->height + 10) {
        p.moveDown(time);
    }
}