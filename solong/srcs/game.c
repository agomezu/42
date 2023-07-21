#include "../includes/so_long.h"

t_tile  load_tile(void *mlx, char *filename, t_game *game)
{
    t_tile  tile;
    int     bits_per_pixel;
    int     line_length;
    int     endian;

    tile.img = mlx_xpm_file_to_image(mlx, filename, &tile.width, &tile.height);
    if (!tile.img)
    {
        write(2, "Error: failed to load tile\n", 27);
        close_game(game);
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
        close_game(game);
        exit(1);
    }
    // Create window
    window_width = game->map_width * TILE_SIZE;
    window_height = game->map_height * TILE_SIZE;
    game->win = mlx_new_window(game->mlx, window_width, window_height, "so_long");
    if (!game->win)
    {
        write(2, "Error: failed to create window\n", 30);
        close_game(game);
        exit(1);
    }
    game->img_data.img = mlx_new_image(game->mlx, window_width, window_height);
    game->img_data.addr = mlx_get_data_addr(game->img_data.img,
                                            &(game->img_data.bits_per_pixel),
                                            &(game->img_data.line_length),
                                            &(game->img_data.endian));
    // Set up the event hooks
    mlx_hook(game->win, 2, 0, key_press, game);     // Key press event
    mlx_hook(game->win, 17, 0, close_game, game);   // Window close event
    // Load the tiles
    game->tiles.wall = load_tile(game->mlx, "./imgs/wall.xpm", game);
    game->tiles.floor = load_tile(game->mlx, "./imgs/floor.xpm", game);
    game->tiles.player = load_tile(game->mlx, "./imgs/player.xpm", game);
    game->tiles.collectible = load_tile(game->mlx, "./imgs/collectible.xpm", game);
    game->tiles.exit = load_tile(game->mlx, "./imgs/exit.xpm", game);
}

void    move_player(t_game *game, t_point direction)
{
    t_point     new_pos;
    t_point     old_pos;

    old_pos = game->player.pos;
    // Calculate the player's new position
    new_pos.x = game->player.pos.x + direction.x;
    new_pos.y = game->player.pos.y + direction.y;
    // Check if the new position is valid (not a wall and within the map bounds)
    if (game->map[new_pos.y][new_pos.x] == '1')
        return ;
    game->player.pos = new_pos;
    game->player.moves++;
    render_tile(game, game->tiles.floor, old_pos.x, old_pos.y);
    render_tile(game, game->tiles.player, game->player.pos.x, game->player.pos.y);
    if (game->map[new_pos.y][new_pos.x] == 'C')
    {
        game->collectibles--;
        game->map[new_pos.y][new_pos.x] = '0';
    }
    if (game->map[new_pos.y][new_pos.x] == 'E' && game->collectibles == 0)
        end_game(game);
    render_game(game);
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