#include "../includes/so_long.h"

/* load_xmp implementation using mlx_xpm_file_to image */
void    *load_xpm(void *mlx_ptr, char *path, int *width, int *height)
{
    void    *img_ptr;

    img_ptr = mlx_xpm_file_to_image(mlx_ptr, path, width, height);
    if (!img_ptr)
    {
        write(2, "Error\nCould not load XPM file\n", 30);
        return (NULL);
    }
    return (img_ptr);
}

/* Init static tiles */
int     init_tile(void *mlx_ptr, t_tile *tile, char *path)
{
    tile->mlx = mlx_ptr;
    tile->img = load_xpm(mlx_ptr, path, &tile->width, &tile->height);
    if (!tile->img)
        return (0);
    tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
                                    &tile->line_length, &tile->endian);
    if (!tile->addr)
        return (0);
    tile->is_animated = 0;
    return (1);
}

/* Init animated tiles */
int     init_anim(t_tile *tile, t_anim *anim, char **paths, int frame_count)
{
    int     i;

    anim->imgs = malloc(sizeof(void *) * frame_count);
    anim->addrs = malloc(sizeof(char *) * frame_count);
    if (!anim->imgs || !anim->addrs)
        return (0);
    i = 0;
    while (i < frame_count)
    {
        anim->imgs[i] = load_xpm(tile->mlx, paths[i], &anim->width, &anim->height);
        if (!anim->imgs[i])
            return (0);
        anim->addrs[i] = mlx_get_data_addr(anim->imgs[i], &anim->bits_per_pixel,
                                            &anim->line_length, &anim->endian);
        if (!anim->addrs[i])
            return (0);
        i++;
    }
    anim->frame_count = frame_count;
    anim->current_frame = 0;
    anim->delay = 100000*2;
    anim->next_frame_time = 100000;
    return (1);
}

/*************************************************************/

int     init_tiles(t_game *game)
{
    // Animted tiles paths
    char    *player_anim_paths[5];
    char    *collec_anim_paths[4];
    // Static tiles paths
    char    wall_path[17];
    char    floor_path[18];
    char    exit_path[17];
    // Animated tiles frame count and index
    int     player_anim_frame_count;
    int     collec_anim_frame_count;
    int     i;

    // Defining paths and frame count
    player_anim_paths[0] = "./imgs/player_1.xpm";
    player_anim_paths[1] = "./imgs/player_2.xpm";
    player_anim_paths[2] = "./imgs/player_3.xpm";
    player_anim_paths[3] = "./imgs/player_4.xpm";
    player_anim_paths[4] = "./imgs/player_5.xpm";
    player_anim_frame_count = 5;
    collec_anim_paths[0] = "./imgs/collectible_1.xpm";
    collec_anim_paths[1] = "./imgs/collectible_2.xpm";
    collec_anim_paths[2] = "./imgs/collectible_3.xpm";
    collec_anim_paths[3] = "./imgs/collectible_4.xpm";
    collec_anim_frame_count = 4;
    ft_strlcpy(wall_path, "./imgs/wall.xpm", 17);
    ft_strlcpy(floor_path, "./imgs/floor.xpm", 18);
    ft_strlcpy(exit_path, "./imgs/exit.xpm", 17);
    i = 0;
    while (i < TOTAL_TILES)
    {
        if (i == PLAYER_TILE)
        {
            game->tiles[i].mlx = game->mlx;
            if(!init_anim(&game->tiles[i], &game->tiles[i].anim, player_anim_paths, player_anim_frame_count))
                return (0);
            game->tiles[i].is_animated = 1;
        }
        if (i == COLLEC_TILE)
        {
            game->tiles[i].mlx = game->mlx;
            if (!init_anim(&game->tiles[i], &game->tiles[i].anim, collec_anim_paths,collec_anim_frame_count))
                return (0);
            game->tiles[i].is_animated = 1;
        }
        if (i == WALL_TILE)
            if (!init_tile(game->mlx, &game->tiles[i], wall_path))
                return (0);
        if (i == FLOOR_TILE)
            if (!init_tile(game->mlx, &game->tiles[i], floor_path))
                return (0);
        if (i == EXIT_TILE)
            if (!init_tile(game->mlx, &game->tiles[i], exit_path))
                return (0);
        i++;
    }
    return (1);
}

int     init_image(t_game *game)
{
    game->img_data.img = mlx_new_image(game->mlx, game->map_width * TILE_SIZE,
                                        game->map_height * TILE_SIZE);
    if (!game->img_data.img)
    {
        write(2, "Error\nFailed to create image\n", 29);
        close_game(game);
    }
    game->img_data.addr = mlx_get_data_addr(game->img_data.img,
                                            &game->img_data.bits_per_pixel,
                                            &game->img_data.line_length,
                                            &game->img_data.endian);
    if (!game->img_data.addr)
    {
        write(2, "Error\nFailed to get image data\n", 31);
        close_game(game);
    }
    mlx_hook(game->win, 2, 0, key_press, game);     // Key press event!
    mlx_hook(game->win, 17, 0, close_game, game);   // Window close event
    return (1);
}

/* Main function of the process */
void    init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        write(2, "Error\nFailed to initialize MinilibX\n", 36);
        close_game(game);
    }
    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
                                game->map_height * TILE_SIZE, "so_long");
    if (!game->win)
    {
        write(2, "Error\nFailed to create window\n", 30);
        close_game(game);
    }
    game->time = 0;
    init_image(game);
    if(!init_tiles(game))
    {
        write(2, "Error\nLoading and initiating the tiles\n", 39);
        close_game(game);
    }
}