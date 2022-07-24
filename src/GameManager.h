/*
 * Ball.h
 *
 *  Created on: 6/7/22.
 *      Author: Jordian
 */


#ifndef PONG_GAME_GAMEMANAGER_H
#define PONG_GAME_GAMEMANAGER_H

#include "Ball.h"
#include "Paddle.h"

class GameManager                       // class to manage the game, i.e. ball and paddle
{
private:
    int width, height;                  // width and height of the game window
    int score1, score2;                 // score of player1 and player2
    char up1, down1, up2, down2;        // variables to store keys that will player 1, 2 up and down.
    bool quit;                          // for starting and exiting the game.

    Ball *ball;                         // Pointer to ball class instance object
    Paddle *player1;                    // pointer to paddle class instance object. player1
    Paddle *player2;                    // pointer to paddle class instance object. player2

public:
    GameManager(int w, int h);          // Constructor accepting parameters, width and height.
    ~GameManager();                     // Destructor to free up dynamic memory. Deleting pointers.
    void ScoreUp(Paddle *player);       // Function to increase score of the player.
    void Draw();                        // Function to draw the game window, ball, paddle.
    void Input();                       // Function to take user input.
    void Logic();                       // Logic of the game. Ball hitting paddle or left, right wall fo the game screen.

    void Run();                         // Function to run the game.
};


#endif //PONG_GAME_GAMEMANAGER_H
