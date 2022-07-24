/*
 * Paddle.h
 *
 *  Created on: 6/7/22.
 *      Author: Jordian
 */

#include <iostream>
#include "Paddle.h"

using namespace std;

Paddle::Paddle()
{
    // initial position to 0
    x = 0;
    y = 0;
}


Paddle::Paddle(int posX, int posY) : Paddle()
{
    originalX = posX;               // Default x coordinate of ball.
    originalY = posY;               // default y coordinate of ball.

    x = posX;                       // value of x as game starts.
    y = posY;                       // value of y as game starts.
}


void Paddle::Reset()
{
    x = originalX;                  // reset value of x
    y = originalY;                  // reset value of y
}