#include "../includes/so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void render_game(t_game *game)
{
    int x;
    int y;

    // Loop through each tile in the map
    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            t_tile tile;

            // Determine what kind of tile it is
            if (game->map[y][x] == '1')
                tile = game->tiles.wall;
            else if (game->map[y][x] == 'C')
                tile = game->tiles.collectible;
            else if (game->map[y][x] == 'E')
                tile = game->tiles.exit;
            else if (game->map[y][x] == 'P')
                tile = game->tiles.player;
            else
                tile = game->tiles.floor;
            // Draw the tile at the correct position in the window
            mlx_put_image_to_window(game->mlx, game->win, tile.img, x * TILE_SIZE, y *TILE_SIZE);
        }
    }
}