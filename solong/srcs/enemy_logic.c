#include "../includes/so_long.h"

int     random_range(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int     floor_tiles_counter(t_game *game, int *floor_tiles_count)
{
    int y;
    int x;

    floor_tiles_count = 0;
    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == FLOOR_TILE)
                floor_tiles_count++;
            x++;
        }
        y++;
    }
}

void    init_enemies(t_game *game)
{
    int     floor_tiles_count;
    char    enemy_anim_paths[4];
    int     enemy_anim_frame_count;
    t_enemy *enemy;

    srand(time(NULL));
    floor_tiles_counter(game, &floor_tiles_count);
    if (floor_tiles_count < MIN_ENEMIES)
    {
        game->enemy_count = 0;
        return ;
    }
    else if (floor_tiles_count < MAX_ENEMIES)
    {
        game->enemy_count = floor_tiles_count;
    }
    else
    {
        game->enemy_count = random_range(MIN_ENEMIES, MAX_ENEMIES);
    }
    game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
}