#include <raylib.h>
#include "../lib/physics.h"

int main (void)
{
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Physics! YAY");

    PhysicsObject ball = CreatePhysicsObject(screenWidth/2.0f, screenHeight/2.0f, 1.0f);

    PhysicsObject stationary = CreatePhysicsObject(screenWidth/2.0f, screenHeight/1.5f, 0.0f);

    stationary.acceleration.y = 0.0f;
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

        if (fabs(ball.position.y - stationary.position.y) < 50.0f) { 
            ball.velocity.y = -ball.velocity.y;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(ball.position, 20, RED);
            DrawCircleV(stationary.position, 40, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}