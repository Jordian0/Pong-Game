/*
 * Paddle.h
 *
 *  Created on: 6/7/22.
 *      Author: Jordian
 */

#ifndef PONG_GAME_PADDLE_H
#define PONG_GAME_PADDLE_H


class Paddle {                      // class for the paddle, that bounces the ball.
private:
    int x, y;                       // for coordinates of the paddle.
    int originalX, originalY;       // default position of the paddle.

public:
    Paddle();                       // constructor to initialize x, y.
    Paddle(int posX, int posY);     // constructor that will set position by the parameters.

    void Reset();                   // function to reset the position of the paddle

    inline int getX() { return x; } // Function to get x coordinate of the paddle. Private data member.
    inline int getY() { return y; } // Function to get y coordinate of the paddle. Private data member.

    inline void moveUp() { y--; }   // Function to move paddle up
    inline void moveDown() { y++; } // Function to move paddle down
};


#endif //PONG_GAME_PADDLE_H
