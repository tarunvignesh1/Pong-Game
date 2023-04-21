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


	Rectangle GetRect() 
	{
		return Rectangle{(x - width / 2),(y - height / 2), width, height };
	}

	void Draw()
	{
		DrawRectangleRec(GetRect(),YELLOW);
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

	Paddle leftpaddle{};

	leftpaddle.x = 50;
	leftpaddle.y = GetScreenHeight() / 2;
	leftpaddle.width = 10;
	leftpaddle.height = 100;
	leftpaddle.speed = 500;

	Paddle rightpaddle{};

	rightpaddle.x = GetScreenWidth() - 50;
	rightpaddle.y = GetScreenHeight() / 2;
	rightpaddle.width = 10;
	rightpaddle.height = 100;
	rightpaddle.speed = 500;

	const char* Winnertext = nullptr;


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

		//Interaction with paddles
		//left paddle motion control

		if (IsKeyDown(KEY_W))
		{
			leftpaddle.y -= leftpaddle.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S))
		{
			leftpaddle.y += leftpaddle.speed * GetFrameTime();
		}

		//right paddle motion control

		if (IsKeyDown(KEY_UP))
		{
			rightpaddle.y -= rightpaddle.speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_DOWN))
		{
			rightpaddle.y += rightpaddle.speed * GetFrameTime();
		}

		//Collision Check

		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, leftpaddle.GetRect()))
		{
			if (ball.SpeedX < 0)
			{
				ball.SpeedX *= -1.01f;
				ball.SpeedY = (ball.y - leftpaddle.y) / (leftpaddle.height / 2) * ball.SpeedX;
			}
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, rightpaddle.GetRect()))
		{
			if (ball.SpeedX > 0)
			{
				ball.SpeedX *= -1.01f;
				ball.SpeedY = (ball.y - rightpaddle.y) / (rightpaddle.height / 2) * abs(ball.SpeedX);
			}
		}

		if (ball.x < 0)
		{
			Winnertext = "RIGHT PLAYER WINS";
		}
		if (ball.x > GetScreenWidth())
		{
			Winnertext = "LEFT PLAYER WINS";
		}

		BeginDrawing();
		ClearBackground(BLACK);

		ball.Draw();
		leftpaddle.Draw();
		rightpaddle.Draw();

		if (Winnertext)
		{
			int textwidth = MeasureText(Winnertext, 60);
			DrawText(Winnertext, GetScreenWidth()/2-textwidth/2, GetScreenHeight() / 2 - 30, 60, YELLOW);
		}
		// Restart game

		if (Winnertext && IsKeyPressed(KEY_SPACE))
		{
			ball.x = GetScreenWidth() / 2;
			ball.y = GetScreenHeight() / 2;
			ball.SpeedX = 300;
			ball.SpeedY = 300;
			Winnertext = nullptr;
		}

		DrawFPS(10, 10);
		EndDrawing();
	}
	CloseWindow();

}