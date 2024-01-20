#include "include/player.h"
#include <stdlib.h>
#include <stdio.h>

Player* init_player(Vector2 pos, Vector2 size,Vector2 hitbox, Texture2D spritesheet, float speed, int offset, float jump_force)
{
    Player* player = calloc(1, sizeof(Player));

    player->pos = pos;
    player->size = size;
    player->hitbox.x = hitbox.x * SIZE_MULTIPLIER;
    player->hitbox.y = hitbox.y * SIZE_MULTIPLIER;
    player->spritesheet = spritesheet;
    player->speed = speed;
    player->facing = 1;
    player->offset = offset;
    player->canJump = true;
    player->jump_force = jump_force;

    return player;
}
void update_player(Player* player, Tilemap* tiles)
{
    int input_x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);

    if(input_x > 0)
    {
        player->facing = 1;
    }
    else if(input_x < 0)
    {
        player->facing = -1;
    }
    
    if(IsKeyPressed(KEY_ENTER)) player->facing *= -1;

    if(IsKeyPressed(KEY_SPACE) && player->canJump)
    {
        player->canJump = false;
        player->vel_y = player->jump_force;
    }

    player->pos.x += input_x * player->speed * GetFrameTime();


    if(player->pos.x + (player->size.x - player->offset) * SIZE_MULTIPLIER > WIDTH)
    {
        player->pos.x = WIDTH - player->size.x * SIZE_MULTIPLIER + player->offset * SIZE_MULTIPLIER;
    }
    else if(player->pos.x + player->offset * SIZE_MULTIPLIER < 0)
    {
        player->pos.x = - player->offset * SIZE_MULTIPLIER;
    }

    if(!player->canJump)
    {
        player->vel_y += GRAVITY * GetFrameTime();
        player->pos.y += player->vel_y * GetFrameTime();
    }
    else
    {
    }

    int obstacle_hit = 0;

    float ground_handler = player->vel_y/4 * GetFrameTime() + .5f;

    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 24; j++)
        {
                Tile* tile = tiles->tiles[i][j];
                if(tile->type != 2) continue;
                if(
                player->vel_y > 0 &&
                !player->canJump &&
                !obstacle_hit &&
                player->pos.y + player->size.y * SIZE_MULTIPLIER > tile->pos.y &&
                player->pos.y + (player->size.y - ground_handler) * SIZE_MULTIPLIER < tile->pos.y &&
                player->pos.x + (player->size.x - player->offset) * SIZE_MULTIPLIER > tile->pos.x &&
                player->pos.x + player->offset * SIZE_MULTIPLIER < tile->pos.x + tile->size.x)
                {
                    obstacle_hit = 1;
                    player->canJump = true;
                    player->vel_y = 0;
                    player->pos.y = tile->pos.y - player->size.y * SIZE_MULTIPLIER;
                }
        }
    }
    if(!obstacle_hit) player->canJump = false;
    printf("%0.3f\n", ground_handler);

    if(IsKeyPressed(KEY_SPACE) && player->canJump)
    {
        player->canJump = false;
        player->vel_y = player->jump_force;
    }
}


void draw_player(Player* player)
{
    DrawTexturePro(player->spritesheet,
    (Rectangle){0, 0, player->facing * player->size.x, player->size.y},
    (Rectangle){player->pos.x, player->pos.y, player->size.x * SIZE_MULTIPLIER, player->size.y * SIZE_MULTIPLIER},
    (Vector2){0, 0},
    0, WHITE);
}