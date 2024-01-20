#include "include/tilemap.h"
#include "include/game_manager.h"
#include <stdlib.h>

Tilemap* init_tilemap(const int tiles_map[24][24], Vector2 start_pos, Vector2 tile_size, Texture2D spritesheet_texture)
{
    Tilemap* tilemap = calloc(1, sizeof(Tilemap));

    Vector2 pos = start_pos;

    tilemap->texture = spritesheet_texture;
    
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 24; j++)
        {
            tilemap->tiles[i][j] = init_tile(pos, tile_size, tiles_map[i][j] );
            pos.x += tile_size.x * SIZE_MULTIPLIER;
        }
        pos.y += tile_size.y * SIZE_MULTIPLIER;
        pos.x = start_pos.x;
    }

    return tilemap;
}
void draw_tilemap(Tilemap* tilemap)
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 24; j++)
        {
            draw_tile(tilemap->tiles[i][j], tilemap->texture);
        }
    } 
}