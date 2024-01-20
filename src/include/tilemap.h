#ifndef TILEMAP_H
#define TILEMAP_H
#include "tile.h"

typedef struct Tilemap
{
    Tile* tiles[24][24];
    Texture2D texture;
} Tilemap;

Tilemap* init_tilemap(const int tiles_map[24][24], Vector2 start_pos, Vector2 tile_size, Texture2D spritesheet_texture);

void draw_tilemap(Tilemap* tilemap);

#endif