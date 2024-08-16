# Snake Game

## Overview

This is a simple implementation of the classic Snake game in C++. The game involves controlling a snake to eat fruit and grow while avoiding collisions with itself and the screen edges.

## Components

### Global Variables

- **gameOver**: A boolean flag indicating whether the game is over.
- **width**: The width of the game board.
- **height**: The height of the game board.
- **x, y**: The current position of the snake's head.
- **fruitX, fruitY**: The position of the fruit.
- **score**: The player's current score.
- **tailX, tailY**: Arrays to store the positions of the snake's tail segments.
- **nTail**: The number of tail segments.
- **dir**: The current direction of the snake (STOP, LEFT, RIGHT, UP, DOWN).

### Functions

#### `void Ssetup()`
Initializes the game state:
- Sets `gameOver` to `false` and `dir` to `STOP`.
- Places the snake's head in the center of the board.
- Randomly places the fruit.
- Sets the initial score to 0.

#### `void Draw()`
Draws the game board to the console:
- Draws the game boundary and the snake.
- Displays the fruit and the snake's tail.
- Prints the current score.

#### `void Input()`
Handles user input:
- Reads keyboard input to change the direction of the snake.
- 'a' moves the snake left, 'd' moves it right, 'w' moves it up, 's' moves it down.
- 'x' ends the game.

#### `void Logic()`
Updates the game logic:
- Moves the snake in the current direction.
- Updates the positions of the tail segments.
- Checks for collisions with the tail and updates the game over state if needed.
- Wraps the snake around the screen edges.
- Checks if the snake has eaten the fruit and updates the score and fruit position accordingly.

### Main Loop

The `main` function initializes the game with `Ssetup()`, then continuously:
- Draws the game state using `Draw()`.
- Processes user input using `Input()`.
- Updates the game state using `Logic()`.
- Sleeps for 30 milliseconds between updates to control the game speed.

The game continues to run until `gameOver` is set to `true`, at which point it waits for a key press before exiting.

## Getting Started

1. **Compile the Code**: Use a C++ compiler to compile the `snake_game` code. For example, with `g++`:
   ```bash
   g++ -o snake_game snake_game.cpp
