#pragma once

#include <raylib.h>
#include <print>

namespace Renderer 
{
    void Init();
    bool isRunning();
    float deltaTime();
    void StartFrame();
    void EndFrame();
}