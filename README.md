# Pong Game

This is a simple implementation of the classic Pong game using the `raylib` library in C++. The game features a ball and two paddles that can be controlled by the players. The objective of the game is to hit the ball with the paddles and score points by making the ball pass the opponent's paddle.

## How to Play

- Use the **W** and **S** keys to control the left paddle, and the **Up Arrow** and **Down Arrow** keys to control the right paddle.
- The ball will start in the center of the screen and move in a random direction.
- The paddles can be used to hit the ball and change its direction.
- If the ball passes the opponent's paddle, a point is scored.
- The game continues until one player reaches the winning score.
- Press the **Space** key to restart the game after a player wins.

## Game Components

### Ball

- The ball is represented by a circle on the screen.
- It has a position (x, y), a radius, and a speed in the x and y directions.
- The ball moves continuously by updating its position based on its speed.
- When the ball reaches the top or bottom of the screen, it bounces off by changing the sign of its y speed.

### Paddles

- There are two paddles, one on the left side and one on the right side of the screen.
- Each paddle has a position (x, y), a width, a height, and a speed.
- The paddles can be moved up and down by the players using the designated keys.
- The paddles are represented by rectangles on the screen.

### Collision Detection

- The game checks for collisions between the ball and the paddles using the `CheckCollisionCircleRec()` function.
- If a collision is detected, the ball's speed is updated based on the position and size of the paddle it collided with.

### Win Condition

- The game checks if the ball goes beyond the left or right edge of the screen.
- If the ball goes beyond the left edge, the right player wins.
- If the ball goes beyond the right edge, the left player wins.
- The winning player's name is displayed on the screen.

### Restarting the Game

- After a player wins, the game can be restarted by pressing the **Space** key.
- When the game is restarted, the ball's position, speed, and the winning player's name are reset.

## Dependencies

- This program uses the `raylib` library for graphics and input handling. Make sure to have `raylib` installed and linked properly.

## Building and Running the Game

1. Include the necessary headers: `<iostream>` and `"raylib.h"`.
2. Define the `Ball` and `Paddle` structs with their respective member variables and member functions.
3. Implement the `main()` function.
4. Initialize the game window using `InitWindow()`.
5. Set the window state to enable vertical synchronization using `SetWindowState()`.
6. Create instances of the `Ball` and `Paddle` structs and set their initial values.
7. Enter the game loop using a `while` loop that runs until the window is closed.
8. Update the ball's position based on its speed.
9. Check for collisions between the ball and the paddles.
10. Check for win conditions and update the winning player's name.
11. Handle input to control the paddles.
12. Draw the game objects on the screen using the `raylib` drawing functions.
13. Restart the game if the restart key is pressed.
14. Close the game window using `CloseWindow()`.

## Acknowledgements

This implementation is based on various tutorials and resources available online, including the `raylib` documentation and community examples.

**Note:** This readme assumes basic knowledge of C++ and the `raylib` library. For more detailed explanations and tutorials, refer to the official `raylib` documentation and other learning resources.
