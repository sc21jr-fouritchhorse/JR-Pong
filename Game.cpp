#include "Game.h"

Game::Game() = default;

void Game::SetPositionsInitial()
{
    paddle1.position = vec2(0.0f, this->win_h / 2.0f);
    paddle2.position = vec2(this->win_w, this->win_h / 2.0f);
    ball.position = vec2(win_w / 2.0f , win_h / 2.0f);
    ball.velocity.x = cos(maxBallSpeed) * (float) (-1 + (rand() % 1));
    ball.velocity.y = sin(maxBallSpeed) * (float) (-1 + (rand() % 1));
}

void Game::Init(float w, float h) 
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->win_w = w;
    this->win_h = h;

    game_window = glfwCreateWindow(win_w, win_h, "PONG", NULL, NULL);
    
    glfwMakeContextCurrent(game_window);

    paddle1 = pong_entity(vec2());
    paddle2 = pong_entity(vec2());
    paddle1.scale.y == paddle2.scale.y == paddleHeight;
    ball = pong_entity(vec2());

    SetPositionsInitial();

    entities.push_back(&ball);
    entities.push_back(&paddle1);
    entities.push_back(&paddle2);

    score = 0;

    frameNo = 0;
    isRunning = true;
}

void Game::Run()
{
    while (isRunning)
    {   
        GetInput();
        Update();
        Draw();

        glfwPollEvents();
    }
}

void Game::GetInput() 
{
    if(glfwGetKey(game_window, GLFW_KEY_Q) || 
    glfwGetKey(game_window, GLFW_KEY_ESCAPE))
        isRunning = false;
    if(glfwGetKey(game_window, GLFW_KEY_R))
    {
        SetPositionsInitial();
    }
    
    if(glfwGetKey(game_window, GLFW_KEY_W) && paddle1.position.y > 0)
    {
        paddle1.velocity.y = -maxPaddleSpd;
    }
    else if(glfwGetKey(game_window, GLFW_KEY_S) && paddle1.position.y < win_h)
    {
        paddle1.velocity.y = maxPaddleSpd;
    }    
    else
    {
        paddle1.velocity.y = 0.0f;
    }  

    if(glfwGetKey(game_window, GLFW_KEY_I) && paddle2.position.y > 0)
    {
        paddle2.velocity.y = -maxPaddleSpd;
    }
    else if(glfwGetKey(game_window, GLFW_KEY_K) && paddle2.position.y < win_h)
    {
        paddle2.velocity.y = maxPaddleSpd;
    }    
    else
    {
        paddle2.velocity.y = 0.0f;
    }   
}

void Game::Update() 
{ 
 
    paddle1.Update();
    paddle2.Update();
    
    if(ball.position.y > win_h || ball.position.y < 0.0f)
        ball.velocity.y *= -1.0f;
    
    if (ball.position.x > win_w) {
        score += 1;
        SetPositionsInitial();
    } 
    if (ball.position.x < 0.0f) {
       score -= 1;
       SetPositionsInitial();
    }

    
    if(ball.position.x == paddle1.position.x && 
    ball.position.y < (paddle1.position.y + paddle1.scale.y / 2.0f)
    && ball.position.y > (paddle1.position.y - paddle1.scale.y / 2.0f))
    {
        ball.velocity.x *= -1;
    }

    if(ball.position.x == paddle2.position.x && 
    ball.position.y < (paddle2.position.y + paddle2.scale.y / 2.0f)
    && ball.position.y > (paddle2.position.y - paddle2.scale.y / 2.0f))
    {
        ball.velocity.x *= -1;
    }

    ball.Update();
}

void Game::Draw() 
{
    printf("Player 1 position: %f\t", paddle1.position.y);
    printf("Player 2 position: %f\t", paddle2.position.y);
    printf("Ball position: %f,%f\t", ball.position.x, ball.position.y);
    printf("Score: %d\r", score);

    glfwSwapBuffers(game_window);
}