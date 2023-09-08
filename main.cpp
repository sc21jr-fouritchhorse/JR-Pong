#include "Game.h"

int main() {
    
    Game pong;
    pong.Init(800.0f, 600.0f);
    pong.Run();

    return 0;
}