#include "../includes/so_long.h"

t_tile  *get_tile_from_char(t_game *game, char c)
{
    if (c == WALL)
        return (&game->tiles[WALL_TILE]);
    else if (c == COLLEC)
        return (&game->tiles[COLLEC_TILE]);
    else if (c == EXIT)
        return (&game->tiles[EXIT_TILE]);
    else if (c == FLOOR)
        return (&game->tiles[FLOOR_TILE]);
    else if (c == PLAYER)
        return (&game->tiles[FLOOR_TILE]);
    else
        return (NULL);
}

int     game_loop(t_game *game)
{
    t_tile  *tile;
    t_anim  *anim;
    int     i;
    int     j;

    if (game->is_game_over)
        return (0);
    i = 0;
    // Update animation frames
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            tile = get_tile_from_char(game, game->map[i][j]);
            if (tile && tile->is_animated)
            {
                anim = &tile->anim;
                if (game->time >= anim->next_frame_time)
                {
                    anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
                    anim->next_frame_time = game->time + anim->delay;
                }
            }
            j++;
        }
        i++;
    }
    game->time++;
    render_game(game);
    usleep(100000);
    return (1);
}