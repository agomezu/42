#include "../includes/so_long.h"

// Need to check this
int     close_game(t_game *game)
{
    int     i;

    i = 0;
    // Free the map
    while (i < game->map_height && game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    if (game->map != NULL)
        free(game->map);
    if (game->mlx != NULL && game->win != NULL)
    {
        mlx_destroy_image(game->mlx, game->tiles.wall.img);
        mlx_destroy_image(game->mlx, game->tiles.floor.img);
        mlx_destroy_image(game->mlx, game->tiles.player.img);
        mlx_destroy_image(game->mlx, game->tiles.collectible.img);
        mlx_destroy_image(game->mlx, game->tiles.exit.img);
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
    }
    exit(0);
}

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