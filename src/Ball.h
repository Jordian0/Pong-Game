/*
 * Ball.h
 *
 *  Created on: 6/7/22.
 *      Author: Jordian
 */

#ifndef PONG_GAME_BALL_H
#define PONG_GAME_BALL_H

enum Direction { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Ball {                            // ball class
private:
    int x, y;                           // for coordinates of the Ball
    int originalX, originalY;             // default position of the Ball
    Direction dir;

public:
    Ball(int posX, int posY);           // Constructor that will set position by the parameters.
    void Reset();                       // Function to reset the position of the ball.
    void ChangeDirection(Direction d);  // Function with arguments x and y coordinates of ball.r changing the direction of the ball.
    void RandomDirection();             // Function to change the direction of the ball after hitting.

    // Inline functions are the functions that compiler didn't actually call the function but replace the code in current position.
    inline int getX() { return x; }     // Function to get x coordinate of the ball. Private data member
    inline int getY() { return y; }     // Function to get y coordinate of the ball. Private data member.
    inline Direction getDirection() { return dir; }       // Function to get dir of the ball. Private data member.

    void Move();                        // Function to move the ball. (changing x, y coordinates of the ball)
};


#endif //PONG_GAME_BALL_H
