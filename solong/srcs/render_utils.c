#include "../includes/so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    render_tile(t_game *game, t_tile tile, int x, int y)
{
    int tile_x;
    int tile_y;
    int color;

    tile_y = 0;
    while (tile_y < tile.height)
    {
        tile_x = 0;
        while (tile_x < tile.width)
        {
            color = *(unsigned int *)(tile.addr + (tile_y * tile.width + tile_x) * 4);
            if ((color & 0x00FFFFFF) != 0)
                my_mlx_pixel_put(&game->img_data, x * TILE_SIZE + tile_x,
                                y * TILE_SIZE + tile_y, color);
            tile_x++;
        }
        tile_y++;
    }
}

void render_game(t_game *game)
{
    int     x;
    int     y;
    char    *moves_str;
    char    *collectibles_str;

    y = 0;
    mlx_clear_window(game->mlx, game->win);
    // Loop through each tile in the map
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            if (game->map[y][x] == '1')
                render_tile(game, game->tiles.wall, x, y);
            else if (game->map[y][x] == 'C')
                render_tile(game, game->tiles.collectible, x, y);
            else if (game->map[y][x] == 'E')
                render_tile(game, game->tiles.exit, x, y);
            else if (game->map[y][x] == '0')
                render_tile(game, game->tiles.floor, x, y);
            if (game->player.pos.x == x && game->player.pos.y == y) 
                render_tile(game, game->tiles.player, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img_data.img, 0, 0);    
    moves_str = ft_itoa(game->player.moves);
    collectibles_str = ft_itoa(game->collectibles);
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moves: ");
    mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, moves_str);
    mlx_string_put(game->mlx, game->win, 10, game->map_height * TILE_SIZE - 10, 0xFFFFFF, "Collectibles left: ");
    mlx_string_put(game->mlx, game->win, 130, game->map_height * TILE_SIZE - 10, 0xFFFFFF, collectibles_str);
    free(moves_str);
    free(collectibles_str);
}

