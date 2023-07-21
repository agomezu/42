#include "../includes/so_long.h"

int     close_game(t_game *game)
{
    int     i;

    i = 0;
    // Free the map
    while (i < game->map_height)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    mlx_destroy_image(game->mlx, game->tiles.wall.img);
    mlx_destroy_image(game->mlx, game->tiles.floor.img);
    mlx_destroy_image(game->mlx, game->tiles.player.img);
    mlx_destroy_image(game->mlx, game->tiles.collectible.img);
    mlx_destroy_image(game->mlx, game->tiles.exit.img);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    exit(0);
}

void    end_game(t_game *game)
{
    // Here is to define what should happen when the game ends.
    /* Ending the game: You already have an end_game function that is called
    when the player reaches the exit after collecting all collectibles. 
    You may want to add some kind of message or animation to indicate to the player
    that they have won the game. Also, consider what should happen when the game 
    ends - should the program exit immediately, or should there be a delay before
    exiting? */
    write(2, "End game\n", 10);
    close_game(game);
}

int     main(int argc, char **argv)
{
    t_game game = {0};

    if (argc != 2)
    {
        write(2, "Error: wrong number of arguments", 33);
        return (0);
    }
    if (!read_map(argv[1], &game))
    {
        write(2, "Error: failed to read or validate map\n", 37);
        close_game(&game);
    }
    init_game(&game); 
    render_game(&game);
    mlx_key_hook(game.win, key_press, &game);
    mlx_loop(game.mlx);
    return (0);
}