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
		DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, YELLOW);
		DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10, 100, YELLOW);
		DrawFPS(10, 10);
		EndDrawing();
	}
	CloseWindow();

}