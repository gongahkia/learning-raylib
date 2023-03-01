#include "raylib.h"


int main(){

    float character_pos[2] = {400,250}; // temporarily hard coded this to be the centre of the screen
    float enemy_pos[2][2] = {{GetRandomValue(0, 800), GetRandomValue(0,500)},{GetRandomValue(0, 800), GetRandomValue(0,500)}};

    InitWindow(800, 500, "testing");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
    
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) character_pos[1] -= 10.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) character_pos[1] += 10.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) character_pos[0] -= 10.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) character_pos[0] += 10.0f;

    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawCircle(character_pos[0], character_pos[1], 20.0, MAGENTA);
        
        DrawCircle(enemy_pos[0][0], enemy_pos[0][1], 15.0, BLUE);

        DrawCircle(enemy_pos[1][0], enemy_pos[1][1], 15.0, GREEN);

    EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
