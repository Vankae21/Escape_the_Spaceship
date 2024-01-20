#ifndef TILE_H
#define TILE_H
#include "raylib.h"

typedef struct Tile
{
    enum
    {
        PINK_BLOCK,
        GRAY_BLOCK,
        PLATFORM_BLOCK

    } type;
    Vector2 pos;
    Vector2 size;
} Tile;

Tile* init_tile(Vector2 pos, Vector2 size, int type);
void draw_tile(Tile* tile, Texture2D texture);

#endif