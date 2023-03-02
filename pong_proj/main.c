#include "raylib.h"

// ball properties and functions called on the ball

struct Ball{
    float position [2];
    int speed [2];
    int radius;
};

void Draw_ball(float position [2], int radius) {
    DrawCircle(position[0], position[1], radius, WHITE);
}

void Update_ball(float position [2], int speed [2], int radius) {
    position[0] += speed[0];
    position[1] += speed[1];

    // handles the inverse kinematics of the ball should it detect a collision with the wall objects (hard coded instead of actually creating a collision object from the Raylib library)
    if (position[1] + radius >= GetScreenHeight() || position[1] - radius <= 0){
        speed [1] *= -1;
    } if (position[0] + radius >= GetScreenWidth() || position[0] - radius <= 0){
        speed [0] *= -1;
    }
}

// paddle properties and functions called on the paddle

struct Paddle{
    float position [2];
    float dimensions [2]; // {width, height}
    int speed;
};

void Draw_paddle(float position [2], float dimensions [2] ){
    DrawRectangle(position[0], position[1], dimensions[0], dimensions[1], WHITE);
}

void Update_padddle(float position [2], int speed, float dimensions [2]){
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        position[1] -= speed;
    } if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        position[1] += speed;
    } 

    if (position[1] <= 0) {
        position[1] == 0;
    } 
    
    if (position[1] + dimensions[1] >= GetScreenHeight()){
        position[1] = GetScreenHeight() - dimensions[1];
    }
}

void Update_AI(float position [2], float dimensions [2], int speed, float ball_position[2]){

    if (position[1] + dimensions[1]/2 > ball_position[1]){
        position[1] -= speed;
    } if (position[1] + dimensions[1]/2 <= ball_position[1]){
        position[1] += speed;
    }

    if (position[1] <= 0) {
        position[1] == 0;
    } 
    
    if (position[1] + dimensions[1] >= GetScreenHeight()){
        position[1] = GetScreenHeight() - dimensions[1];
    }

}

int main() {
    
    SetTargetFPS(60);
    const int window_width = 1280;
    const int window_height = 800;
    InitWindow(window_width, window_height, "test game");

    struct Ball ball;
    ball.position[0] = window_width/2;
    ball.position[1] = window_height/2;
    ball.speed[0] = 7;
    ball.speed[1] = 7;
    ball.radius = 20;

    struct Paddle player;
    player.dimensions[0] = 25;
    player.dimensions[1] = 120;
    player.position[0] = window_width - player.dimensions[0] -10;
    player.position[1] = window_height/2 - player.dimensions[1];
    player.speed = 6;

    struct Paddle AI; 
    AI.dimensions[0] = 25;
    AI.dimensions[1] = 120;
    AI.position[0] = 10;
    AI.position[1] = window_height/2 - AI.dimensions[1]/2;
    AI.speed = 6;

// Main Game Loop

    while (WindowShouldClose() == false) {

        BeginDrawing();
       
        // ball position and speed updated
        Update_ball(ball.position, ball.speed, ball.radius);

        // player and AI position and speed updated
        Update_padddle(player.position, player.speed, player.dimensions);
        Update_AI(AI.position, AI.dimensions, AI.speed, ball.position);

        // checking for collisions 
        // work on this when i know how it works 

        // update the screen
        ClearBackground(BLACK);

        // ball drawn
        Draw_ball(ball.position, ball.radius);

        // player and AI paddle drawn
        Draw_paddle(player.position, player.dimensions);
        Draw_paddle(AI.position, AI.dimensions);

        // dividing line 
        DrawLine(window_width/2, 0, window_width/2, window_height, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
