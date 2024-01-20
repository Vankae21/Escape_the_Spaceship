#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "game_manager.h"
#include "tile.h"
#include "tilemap.h"

typedef struct Player
{
    Vector2 pos;
    Vector2 size;
    Vector2 hitbox;
    Texture2D spritesheet;
    float speed;
    float vel_y;
    float jump_force;
    int offset;

    bool canJump;

    int facing;


    // animating
    int frame;
    int frame_speed;

    int idle_frame;
    int run_frame;
    int jump_frame;

} Player;

Player* init_player(Vector2 pos, Vector2 size,Vector2 hitbox, Texture2D spritesheet, float speed, int offset, float jump_force);
void update_player(Player* player, Tilemap* tiles);
void draw_player(Player* player);
bool is_colliding_tile(Player* player, Tile** tile);

#endif