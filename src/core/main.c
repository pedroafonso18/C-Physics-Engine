#include <raylib.h>

int main (void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Physics! YAY");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}