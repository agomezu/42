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
    mlx_destroy_window(game->mlx, game->win);
    // free(game);
    // End the program
    exit(0);
}

t_tile  load_tile(void *mlx, char *filename)
{
    t_tile  tile;
    int     bits_per_pixel;
    int     line_length;
    int     endian;

    tile.img = mlx_xpm_file_to_image(mlx, filename, &tile.width, &tile.height);
    if (!tile.img)
    {
        write(2, "Error: failed to load tile\n", 27);
        exit(1);
    }
    tile.addr = mlx_get_data_addr(tile.img, &bits_per_pixel, &line_length, &endian);
    return (tile);
}

void    init_game(t_game *game)
{
    int     window_width;
    int     window_height;

    // Initialize the MinilibX library
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2, "Error: failed to initialize MinilibX\n", 37);
        exit(1);
    }
    // Create window
    window_width = game->map_width * TILE_SIZE;
    window_height = game->map_height * TILE_SIZE;
    game->win = mlx_new_window(game->mlx, window_width, window_height, "so_long");
    if (!game->win)
    {
        write(2, "Error: failed to create window\n", 30);
        exit(1);
    }
    // Set up the event hooks
    mlx_hook(game->win, 2, 0, key_press, game);     // Key press event
    mlx_hook(game->win, 17, 0, close_game, game);   // Window close event
    // Load the tiles
    game->tiles.wall = load_tile(game->mlx, "imgs/wall.xpm");
    game->tiles.floor = load_tile(game->mlx, "imgs/floor.xmp");
    game->tiles.player = load_tile(game->mlx, "imgs/player.xmp");
    game->tiles.collectible = load_tile(game->mlx, "imgs/collectible.xmp");
    game->tiles.exit = load_tile(game->mlx, "imgs/exit.xmp");
}

void    move_player(t_game *game, t_point direction)
{
    t_point     new_pos;

    // Calculate the player's new position
    new_pos.x = game->player.pos.x + direction.x;
    new_pos.y = game->player.pos.y + direction.y;
    // Check if the new position is valid (not a wall and within the map bounds)
    if (is_valid(game, new_pos))
    {
        // Update the player's position
        game->player.pos = new_pos;
        // Re-render the game state
        render_game(game);
    }
}

int     key_press(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        move_player(game, (t_point){0, -1});
    else if (keycode == KEY_A)
        move_player(game, (t_point){-1, 0});
    else if (keycode == KEY_S)
        move_player(game, (t_point){0, 1});
    else if (keycode == KEY_D)
        move_player(game, (t_point){1, 0});
    else if (keycode == KEY_ESC)
        close_game(game);
    return (0);
}