//
//  PaddleAIManager.h
//  MyPongClone
//
//  Created by Aaron McLeod on 2015-05-09.
//  Copyright (c) 2015 Aaron McLeod. All rights reserved.
//

#ifndef __MyPongClone__PaddleAIManager__
#define __MyPongClone__PaddleAIManager__

#include <stdio.h>
#include "Ball.h"
#include "Paddle.h"

class PaddleAIManager {
public:
    void adjustPaddlePosition(Ball &b, Paddle &p, float time);
};

#endif /* defined(__MyPongClone__PaddleAIManager__) */
