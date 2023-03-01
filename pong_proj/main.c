#include "raylib.h"

// ball properties and methods

struct Ball{
    float position [2];
    int speed [2];
    int radius;
};

void Draw_ball(float position [2], int radius) {
    DrawCircle(position[0], position[1], radius, WHITE);
}

void Update_ball(float position [2], int speed [2]) {
    position[0] += speed[0];
    position[1] += speed[1];
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

// Main Game Loop

    while (WindowShouldClose() == false) {

        BeginDrawing();
       
        // ball position and speed updated
        Update_ball(ball.position, ball.speed);

        // update the screen
        ClearBackground(BLACK);

        // ball drawn
        Draw_ball(ball.position, ball.radius);

        // paddles
        DrawRectangle(10, window_height/2 - 60, 25, 120, WHITE); // rectangles are drawn from their top left corner
        DrawRectangle(window_width - 35, window_height/2 - 60, 25, 120, WHITE);

        // dividing line 
        DrawLine(window_width/2, 0, window_width/2, window_height, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
