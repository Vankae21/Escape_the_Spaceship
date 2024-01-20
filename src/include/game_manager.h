#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "player.h"
#include "tilemap.h"
#include "tile.h"

extern const int WIDTH;
extern const int HEIGHT;
extern const char* TITLE;
extern const int FPS;
extern const float SIZE_MULTIPLIER;
extern const float GRAVITY;

void start();
void update();
void late_update();
void end();

#endif