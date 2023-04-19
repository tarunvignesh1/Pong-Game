#include<iostream>
#include"raylib.h"


int main()
{
	InitWindow(800, 600, "Pong");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawFPS(10, 10);
		EndDrawing();
	}
	CloseWindow();

}