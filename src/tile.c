#include "include/tile.h"
#include "include/game_manager.h"
#include <stdlib.h>

Tile* init_tile(Vector2 pos, Vector2 size, int type)
{
    Tile* tile = calloc(1, sizeof(Tile));

    tile->pos = pos;
    tile->size.x = size.x * SIZE_MULTIPLIER;
    tile->size.y = size.y * SIZE_MULTIPLIER;
    tile->type = type;

    return tile;
}
void draw_tile(Tile* tile, Texture2D texture)
{
    DrawTexturePro(texture, (Rectangle){ tile->type * 8 , 0, 8, 8}, (Rectangle){ tile->pos.x, tile->pos.y, tile->size.x, tile->size.y}, (Vector2){0}, 0, WHITE);
}