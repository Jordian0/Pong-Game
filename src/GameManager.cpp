/*
 * Ball.h
 *
 *  Created on: 6/7/22.
 *      Author: Jordian
 */

#include <iostream>
#include <time.h>                   // for time(), random seed for rand()
#include <unistd.h>                 // for usleep()
#include <conio.h>
#include "GameManager.h"

using namespace std;

GameManager::GameManager(int w, int h)
{
    srand(time(NULL));
    quit = false;

    score1 = 0;
    score2 = 0;

    up1 = 'w', up2 = 'i';                             // keys to move player 1 and 2 up
    down1 = 's', down2 = 'k';                         // keys to move player 1 and 2 down

    // width and height of the screen. (parameters passed)
    width = w;
    height = h;

    ball = new Ball(w/2, h/2);              // initial place of the ball, center of the game window
    // (-2 to center the paddle)
    player1 = new Paddle(1, h/2 - 2);       // initial position of the player1 paddle, left side of the game window.
    player2 = new Paddle(w-2, h/2 - 2);     // initial position of the player2 paddle, right side of the game window.
}


GameManager::~GameManager()
{
    // deleting pointers to avoid memory leak
    delete ball;
    delete player1;
    delete player2;
}


void GameManager::ScoreUp(Paddle *player)
{
    // comparing the memory addresses of the player passed with the player object.
    if(player == player1) score1++;
    else if(player == player2) score2++;

    // When score increases by one, game ends.
    // resetting ball and both the paddle's position.
    ball->Reset();
    player1->Reset();
    player2->Reset();
}


void GameManager::Draw()
{
    system("clear");                       // clearing screen

    // printing game wall, ball and paddle
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            // upper and lower wall of the game window
            if(i == 0 || i == height-1)
                cout << "░";

            // left and right wall of the game window
            else if(j == 0 || j == width-1)
                cout << "░";

            else
            {
                int ballx = ball->getX();           // This will get the x coordinate of the ball.
                int bally = ball->getY();           // This will get the y coordinate of the ball.
                int player1x = player1->getX();     // This will get the x coordinate of the player1.
                int player1y = player1->getY();     // This will get the y coordinate of the player1.
                int player2x = player2->getX();     // This will get the x coordinate of the player2.
                int player2y = player2->getY();     // This will get the y coordinate of the player2.


                // ball coordinates
                if(ballx == j && bally == i)
                    cout << "o";

                // player1 paddle in 4 segments
                else if(player1x == j && (player1y == i || player1y+1 == i || player1y+2 == i || player1y+3 == i))
                    cout << "█";

                // player2 paddle in 4 segments
                else if(player2x == j && (player2y == i || player2y+1 == i || player2y+2 == i || player2y+3 == i))
                    cout << "█";

                else
                    cout << " ";                    // empty area of the game window
            }
        }
        cout << endl;
    }

    cout << "\tPlayer1 (Left) to move up \'w\', to move down \'s\'." << endl;
    cout << "\tPlayer2 (right) to move up \'i\', to move down \'k\'." << endl;
    cout << "\tPRESS \'q\' TO QUIT THE GAME." << endl;
    cout << endl;
    cout << "\tScore (Player1) :::  " << score1 << endl;
    cout << "\tScore (Player2) :::  " << score2 << endl;
}


void GameManager::Input()
{
    ball->Move();                                   // to move the ball

    int ballx = ball->getX();                       // This will get the x coordinate of the ball.
    int bally = ball->getY();                       // This will get the y coordinate of the ball.
    int player1x = player1->getX();                 // This will get the x coordinate of the player1.
    int player1y = player1->getY();                 // This will get the y coordinate of the player1.
    int player2x = player2->getX();                 // This will get the x coordinate of the player2.
    int player2y = player2->getY();                 // This will get the y coordinate of the player2.

    if(_kbhit())                        // if keyboard is pressed
    {
        char current = _getch();                    // return the character key that's pressed.
        if (current == up1 && player1x > 0)          // if its equal to the up key of player1
            player1->moveUp();                      // move player1 paddle up
        else if (current == down1 && player1y + 4 < height-1)    // if its equal to the down key of player1
            player1->moveDown();                    // move player1 paddle down
        else if (current == up2 && player2x > 0)     // if its equal to the up key of player2
            player2->moveUp();                      // move player2 paddle up
        else if (current == down2 && player2y + 4 < height-1)    // if its equal to the down key of player2
            player2->moveDown();                    // move player2 paddle down


        // if ball getDirection is stop
        if(ball->getDirection() == STOP)
            ball->RandomDirection();                // randomizing the direction of the ball

        // if current character is equal to 'q' we'll quit the game
        if(current == 'q')
            quit = true;
    }
}


void GameManager::Logic()
{
    int ballx = ball->getX();           // This will get the x coordinate of the ball.
    int bally = ball->getY();           // This will get the y coordinate of the ball.
    int player1x = player1->getX();     // This will get the x coordinate of the player1.
    int player1y = player1->getY();     // This will get the y coordinate of the player1.
    int player2x = player2->getX();     // This will get the x coordinate of the player2.
    int player2y = player2->getY();     // This will get the y coordinate of the player2.

    // left paddle
    for(int i=0; i<4; i++)
    {
        // +1 x coordinate, cause we don't want ball to go in paddle but to hit the paddle
        if(ballx == player1x+1 && bally == player1y+i)          // if ball hit the paddle of player1
            ball->ChangeDirection((Direction)((rand() % 3) + 4));
            // if ball is hit, it'll go right, upright, downright
    }

    // right paddle
    for(int i=0; i<4; i++)
    {
        // -1 x coordinate, cause we don't want ball to go in paddle but to hit the paddle
        if(ballx == player2x-1 && bally == player2y+i)          // if ball hit the paddle of player2
            ball->ChangeDirection((Direction)((rand() % 3) + 1));
            // if ball is hit, it'll go left, upleft, downleft
    }


    // if ball hit the bottom wall of the game window
    if(bally == height-2)
        ball->ChangeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        // if ball hit the bottom wall, it'll bounce upwards

    // if ball hit the upper wall of the game window
    if(bally == 1)
        ball->ChangeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        // if ball hit the upper wall, it'll bounce downwards


    // Scoring up player points
    if(ballx == width-1)                // right wall
        ScoreUp(player1);           // increasing score of player1, player2 missed the ball
    if(ballx == 1)                      // left wall
        ScoreUp(player2);           // increasing score of player2, player1 missed the ball
}


void GameManager::Run()
{
    while(!quit)
    {
        Draw();
        Input();
        Logic();
        usleep(10000);
    }
}
