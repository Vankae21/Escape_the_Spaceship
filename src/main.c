#include "include/game_manager.h"

int main(void)
{

    InitWindow(WIDTH, HEIGHT, TITLE);

    SetTargetFPS(FPS);

    start();

    while(!WindowShouldClose())
    {
        update();

        BeginDrawing();
        ClearBackground(BLUE);
        late_update();
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}