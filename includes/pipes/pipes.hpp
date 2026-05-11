#pragma once

#include <raylib.h>
#include <vector>
struct Pipe
{
    float x;
    float gapY;
    float gapSize = 160.0f;
    float width = 60.0f;
};

class PipeManager
{
private:
    std::vector<Pipe> pipes;
    float scrollSpeed = 200.0f;
    float spacing = 300.0f;

public:
    PipeManager() { Reset(); }
    
    void Reset()
    {
        pipes.clear();

        for (int i = 0; i < 3; i++)
        {
            pipes.push_back({ 400.0f + (i * spacing), (float)GetRandomValue(100, 400) });
        }
    }

    void Update(float deltaTime)
    {
        for (auto& p : pipes)
        {
            p.x -= scrollSpeed * deltaTime;

            if (p.x < -p.width)
            {
                p.x += pipes.size() * spacing;
                p.gapY = (float)GetRandomValue(100, 350);
            }
        }
    }

    void Draw()
    {
        for (const auto& p : pipes)
        {
            DrawRectangle(p.x, 0, p.width, p.gapY, GREEN);
            DrawRectangleLines(p.x, 0, p.width, p.gapY, DARKGREEN);

            DrawRectangle(p.x, p.gapY + p.gapSize, p.width, GetScreenHeight() - (p.gapY + p.gapSize), GREEN);
            DrawRectangleLines(p.x, p.gapY + p.gapSize, p.width, GetScreenHeight() - (p.gapY + p.gapSize), DARKGREEN);
        }
    }
};
