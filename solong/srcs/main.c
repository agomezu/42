#include "../includes/so_long.h"

int    close_game(t_game * game)
{
    int     i;
    int     j;
    t_tile  *tile;
    t_anim  *anim;

    if (game)
    {
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
        // Free the map
        if (game->map)
        {
            i = 0;
            while (i < game->map_height)
            {
                if (game->map[i])
                    free(game->map[i]);
                i++;
            }
            free(game->map);
        }
        i = 0;
        // Free the images and data addresses in the tiles animations
        while (i < TOTAL_TILES)
        {
            tile = &game->tiles[i];
            if (tile->is_animated)
            {
                anim = &tile->anim;
                j = 0;
                while (j < anim->frame_count)
                {
                    if (anim->imgs[j])
                        mlx_destroy_image(tile->mlx, anim->imgs[j]);
                    j++;
                }   
                free(anim->imgs);
                free(anim->addrs);
            }
            else
            {
                if (tile->img)
                    mlx_destroy_image(tile->mlx, tile->img);
            }
            i++;
        }
    }
    printf("Exit\n");
    exit(0);
}

/* Logic of end_game with success */
void    end_game(t_game *game)
{
    char    message[10];
    int     x;
    int     y;
    int     color;

    ft_strlcpy(message, "Game Over", 10);
    write(2, "Game over\n", 10);
    x = (game->map_width * TILE_SIZE) / 2 - 25;
    y = (game->map_height * TILE_SIZE) / 2;
    mlx_clear_window(game->mlx, game->win);
    color = 0xFFFF00;
    mlx_string_put(game->mlx, game->win, x+2, y+2, 0x000000, message);
    mlx_string_put(game->mlx, game->win, x, y, color, message);
    game->is_game_over = 1;
}

/* Main function of the game */
int     main(int argc, char **argv)
{
    t_game game = {0};

    if (argc != 2)
    {
        write(2, "Error: wrong number of arguments", 34);
        return (0);
    }
    if (!read_map(argv[1], &game))
    {
        write(2, "Error: failed to read or validate map\n", 38);
        close_game(&game);
    }
    game.is_game_over = 0;
    init_game(&game); 
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_key_hook(game.win, key_press, &game);
    mlx_loop(game.mlx);
    return (0);
}