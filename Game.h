#ifndef __GL_PONG_GAME__

#define __GL_PONG_GAME__

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>

#include "Objects.h"

class Game {
public:
    Game();
    void Init(float width, float height);
    void Run();
    const float maxPaddleSpd = 5.0f;
    const float maxBallSpeed = 2.5f;
private:
    void GetInput();
    void Update();
    void Draw();
    bool isRunning;
    float win_w;
    float win_h;
    unsigned long frameNo;
    std::vector<Entity*> entities;
    Entity ball;
    Entity paddle1;
    Entity paddle2;
    GLFWwindow *game_window;

};

#endif