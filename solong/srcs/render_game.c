#include "../includes/so_long.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
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
            {
                my_mlx_pixel_put(&game->img_data, x * TILE_SIZE + tile_x, y * TILE_SIZE + tile_y, color); 
            }
            tile_x++;
        }
        tile_y++;
    }
}

void    render_anim(t_game *game, t_anim *anim, int x, int y)
{
    t_tile  temp_tile;

    temp_tile.img = anim->imgs[anim->current_frame];
    temp_tile.addr = anim->addrs[anim->current_frame];
    temp_tile.width = anim->width;
    temp_tile.height = anim->height;
    temp_tile.bits_per_pixel = anim->bits_per_pixel;
    temp_tile.line_length = anim->line_length;
    temp_tile.endian = anim->endian;

    render_tile(game, temp_tile, x, y);
    anim->current_frame = (anim->current_frame + 1) % (anim->frame_count);
}

void    render_game_text(t_game *game)
{
    char    *moves_str;
    char    *collectibles_str;

    moves_str = ft_itoa(game->player.moves);
    collectibles_str = ft_itoa(game->collectibles);
    // Moves text
    mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFFFF, "Moves: ");
    mlx_string_put(game->mlx, game->win, 60, 15, 0xFFFFFF, moves_str);
    // Collectibles left text
    mlx_string_put(game->mlx, game->win, 10, game->map_height * TILE_SIZE - 10, 0xFFFFFF, "Collectibles left: ");
    mlx_string_put(game->mlx, game->win, 130, game->map_height * TILE_SIZE - 10, 0xFFFFFF, collectibles_str);
    free(moves_str);
    free(collectibles_str);
}

void    render_game(t_game *game)
{
    int     x;
    int     y;
    char    tile_type;

    if (game->is_game_over)
        return ;
    mlx_clear_window(game->mlx, game->win);
    y = 0;
    // Loop through each tile in the map
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            // Check double array of game->map and render accordingly
            tile_type = game->map[y][x];
            if (tile_type != EXIT)
                render_tile(game, game->tiles.floor, x, y);
            if (tile_type == WALL)
                render_tile(game, game->tiles.wall, x, y);
            if (tile_type == COLLEC)
                render_anim(game, &game->tiles.collectible.anim, x, y);
            if (tile_type == EXIT)
                render_tile(game, game->tiles.exit, x, y);
            x++;
        }
        y++;
    }
    // Render the player separately at its current position
    render_anim(game, &game->tiles.player.anim,
                game->player.pos.x, game->player.pos.y);
    mlx_put_image_to_window(game->mlx, game->win, game->img_data.img, 0, 0);
    render_game_text(game);
}