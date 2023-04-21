#include<iostream>
#include"raylib.h"

struct Ball
{
	float x, y, radius;
	float SpeedX, SpeedY;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, BLUE);
	}
};

struct Paddle
{
	float x, y;
	float speed;
	float width, height;

	void Draw()
	{
		DrawRectangle(x, y, width, height, YELLOW);
	}
};

int main()
{
	InitWindow(800, 600, "Pong");
	SetWindowState(FLAG_VSYNC_HINT);

	// setting varibales for Ball movement
	Ball ball{};

	ball.x = GetScreenWidth() / 2.0f;
	ball.y = GetScreenHeight() / 2.0f;
	ball.radius = 5;
	ball.SpeedX = 100;
	ball.SpeedY = 300;



	Paddle leftpaddle;

	leftpaddle.x = 50;
	leftpaddle.y = GetScreenHeight() / 2 - 50;
	leftpaddle.width = 10;
	leftpaddle.height = 100;


	Paddle rightpaddle;

	rightpaddle.x = GetScreenWidth() - 50 - 10;
	rightpaddle.y = GetScreenHeight() / 2 - 50;
	rightpaddle.width = 10;
	rightpaddle.height = 100;


	while (!WindowShouldClose())
	{
		//Adding ball speed

		ball.x += ball.SpeedX * GetFrameTime();
		ball.y += ball.SpeedY * GetFrameTime();

		//getting ball conditions to bounce off

		if (ball.y < 0) 
		{
			ball.y = 0;
			ball.SpeedY *= -1;
		}
		if (ball.y > GetScreenHeight())
		{
			ball.y = GetScreenHeight();
			ball.SpeedY *= -1;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		ball.Draw();
		leftpaddle.Draw();
		rightpaddle.Draw();
		DrawFPS(10, 10);
		EndDrawing();
	}
	CloseWindow();

}