#include "../includes/so_long.h"

int     main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        write(2, "Error: wrong number of arguments", 33);
        return (0);
    }
    if (!read_map(argv[1], &game))
    {
        write(2, "Error: failed to read or validate map\n", 37);
        return (0);
    }
    // TODO: Initialise the game state
    // This includes setting up the MinilibX, creating the window, loading textures, etc.
    init_game(&game); 
    render_game(&game);

    // TODO: Enter the game loop
    // This is where the player's inputs are handled and the game state is updated
    mlx_key_hook(game.win, key_press, &game);
    mlx_loop(game.mlx);

    // TODO: Clean up and exit
    // When the game is over, you need to properly deallocate all the resources and exit
}