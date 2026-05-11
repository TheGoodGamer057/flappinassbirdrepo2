#pragma once

#include <raylib.h>
#include <print>

void InitGameSys(int width, int height, const char *title, int targetFPS = 120)
{
    ::InitWindow(width, height, title);
    ::SetTargetFPS(targetFPS);
    std::print("Initial Game System (void InitGameSys()) started at {} FPS\n");
}

bool isRunning()
{
    return !::WindowShouldClose();
}

float deltaTime()
{
    return ::GetFrameTime();
}

void StartFrame(Color color = SKYBLUE)
{
    ::BeginDrawing();
    ::ClearBackground(color);
}

void EndFrame()
{
    EndDrawing();
}