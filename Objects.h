#ifndef __GL_PONG_ECS__
#define __GL_PONG_ECS__

#include <vector>

typedef struct vec2 {
    float x;
    float y;
    vec2(float mX, float mY) {
        x = mX;
        y = mY;
    }
    vec2() {
        x = 0.0f;
        y = 0.0f;
    }
} Vec2;

typedef struct pong_entity {
    //const char *filename;
    //std::vector<Vec2> verts;
    Vec2 scale;
    Vec2 position;
    Vec2 velocity;
    pong_entity() 
    {
        position = vec2(0.0f, 0.0f);
        velocity = vec2(0.0f, 0.0f);
        scale = vec2(1.0f, 1.0f);
    }
    pong_entity(Vec2 initial_pos) 
    {
        position = initial_pos;
        velocity = vec2(0.0f, 0.0f);
        scale = vec2(1.0f, 1.0f);
    }
    void Update() 
    {
        position.x += velocity.x;
        position.y += velocity.y;
    }
    //pong_entity(const char* fn);
} Entity;


#endif