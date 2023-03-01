#include "raylib.h"

int main(){

    float character_pos[] = {0,0};

    InitWindow(800, 500, "testing");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
    
    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) character_pos[1] -= 10.0f;
    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) character_pos[1] += 10.0f;
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) character_pos[0] -= 10.0f;
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) character_pos[0] += 10.0f;

    BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawCircle(character_pos[0], character_pos[1], 20.0, MAGENTA);

        DrawText("Testing", 180, 200, 20, LIGHTGRAY);

    EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
