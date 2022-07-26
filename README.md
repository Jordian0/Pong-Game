
# Pong Game

This is a simple pong game built using C++. There will be two players in the game "Player 1" and "Player 2". They have to hit the ball, if ball touches left wall then Player 2 won. If ball touches right wall then Player 1 won. Their score will be increased by 1 points.

<br/>

## Screenshots
<div align="center">

![App Screenshot](https://raw.githubusercontent.com/Jordian0/Pong-Game/main/screenshots/Screenshot%20from%202022-07-24%2016-36-24.png)
 
</div>


<br/>

## How to play
You can press these keys to change the direction of the paddle.

\
To move Player 1 paddle :

| Key   | Direction   |
|:-----:|:-----------:|
| w     | UP          |
| s     | DOWN        |

<br/>

To move Player 2 paddle :

| Key    | Direction    |
|:------:|:------------:|
| i      | UP           |
| k      | DOWN         |

<br/>

To exit the Pong Game :

| Key    | Direction    |
|:------:|:------------:|
| q      | QUIT         |

<br/>


<br/>

## Libraries we'll need

- [**conio.h**](https://en.wikipedia.org/wiki/Conio.h) : For console input and output. For windows systems you can download the file. For linux systems that file is in the repository.
   ##### For Linux
   - **uninst.h** : usleep() function in linux systems, to slow down the game. usleep() function suspends execution for microsecond intervals.
  ##### For Windows
   - **Windows.h** : Sleep() function in windows systems, to slow down the game. Sleep() function suspends execution for second intervals.

**Other libraries are included in cpp files**

<br/>

## To run the game

` cmake . `does the compiler detection, evaluates the ` CMakeLists.txt ` in the given ` . ` director and generates the build environment in the current working directory.<br/>The ` cmake --build . ` command is an abstraction for the necessary build/make call.



To keep source code clean from any build artifacts you should do "out-of-source" builds.\
\
run [cmake](https://en.wikipedia.org/wiki/CMake) :
```bash
  mkdir build
  cd build
  cmake ..
  cmake --build .
```
\
and finally run [make](https://en.wikipedia.org/wiki/Make_%28software%29) :
```bash
  make
```
\
To run the game :
```bash
  ./game
```

<br/>

## UML Diagram

And this will produce a flow chart:


<div>

```mermaid
classDiagram
    main <|-- GameManager
    GameManager <|-- Ball
    GameManager <|-- Paddle 
    main: main()
    Ball *-- Direction : Composition
    class Direction {
        <<enumeration>>
        STOP : 0
        LEFT : 1
        UPLEFT : 2
        DOWNLEFT : 3
        RIGHT : 4
        UPRIGHT : 5
        DOWNRIGHT : 6
    }
    class Ball{
        -int x, y
        -int originalX, originalY
        -Direction dir
        +Ball(posX, posY)
        +Reset()
        +ChangeDirection(d)
        +RandomDirection()
        +getX() int
        +getY() int
        +getDirection() Direction
        +Move() 
    }
    class Paddle{
        -int x, y
        -int originalX, originalY
        +Paddle()
        +Paddle(posX, posY)
        +Reset()
        +getX() int
        +getY() int
        +moveUp()
        +moveDown()
    }
    class GameManager{
        -int width, height
        -int score1, score2
        -char up1, down1, up2, down2
        -bool quit
        +GameManager(w, h)
        +~GameManager()
        +ScoreUp()
        +Draw()
        +Input()
        +Logic()
        +Run()
    }
```
</div>


<br/>

