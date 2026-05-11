#pragma once

#include <raylib.h>

struct bird
{
    Vector2 position;
    float velocity;
    float gravity = 0.8f;
    float jumpStrength = -10.0f;
    float radius = 20.0f;

    bird(float x, float y) : position({x, y}), velocity(0.0f) {}

    void Update()
    {
        velocity += gravity;
        position.y += velocity;

        if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            velocity = jumpStrength;
        }
    }

    void draw()
    {
        DrawCircleV(position, radius, BLUE);
        DrawCircle(position.x + 10, position.y - 5, 5, BLACK);
    }
};