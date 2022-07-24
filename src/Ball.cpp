/*
 * Ball.cpp
 *
 *   Create on: 6/7/22.
 *      Author: Jordian
 */

#include <iostream>
#include "Ball.h"

using namespace std;

Ball::Ball(int posX, int posY)
{
    originalX = posX;               // Default x coordinate of ball.
    originalY = posY;               // Default y coordinate of ball.

    x = posX;                       // value of x as game starts
    y = posY;                       // value of y as game starts

    dir = STOP;                     // Default state of ball.
}


void Ball::Reset()
{
    x = originalX;                  // reset value of x
    y = originalY;                  // reset value of y

    dir = STOP;                     // State of ball after resetting the ball
}


void Ball::ChangeDirection(Direction d)
{
    dir = d;                        // changing direction of the ball.
}


void Ball::RandomDirection()
{
    // random direction will be from RIGHT, UPRIGHT, DOWNRIGHT, LEFT, UPLEFT, DOWNRIGHT.
    dir = (Direction)((rand() % 6) + 1);    // changing direction of the ball after hitting.
}


void Ball::Move()
{
    switch (dir)
    {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UPLEFT:
            x--; y--;
            break;
        case DOWNLEFT:
            x--; y++;
            break;
        case UPRIGHT:
            x++; y--;
            break;
        case DOWNRIGHT:
            x++; y++;
            break;
        default:
            break;
    }
}