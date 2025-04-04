#include <raylib.h>
#include "../lib/physics.h"

int main (void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Physics! YAY");

    PhysicsObject ball = CreatePhysicsObject(screenWidth/2.0f, screenHeight/2.0f, 1.0f);

    ball.acceleration.y = 9.8f * 30.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        float deltaTime = GetFrameTime();

        UpdatePhysicsObject(&ball, deltaTime);

        if (ball.position.y > screenHeight) {
            ball.position.y = 0;
            ball.position.x = 0;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(ball.position, 20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}