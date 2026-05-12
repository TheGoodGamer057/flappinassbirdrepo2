#include "renderer.hpp"
#include <raylib.h>
#include <print>
#include <cstdio>

namespace Renderer {
    void Init(int width, int height, const char *title, int targetFPS)
    {
        InitWindow(width, height, title);
        SetTargetFPS(targetFPS);
        std::print("Initial Window has FPS set to {}.\n", targetFPS);
    }

    bool isRunning()
    {
        return !::WindowShouldClose();
    }

    float deltaTime()
    {
        return ::GetFrameTime();
    }

    void StartFrame(Color color)
    {
        BeginDrawing();
    }

    void EndFrame()
    {
        EndDrawing();
    }
}