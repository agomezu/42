#ifndef SO_LONG_H
# define SO_LONG

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "minilibx_linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

/* Size of every sprite */
#define TILE_SIZE 32 
#define TOTAL_TILES 5 

/* A simple structure that represents a point in 2D space */
typedef struct s_point
{
    int         x;
    int         y;
}                   t_point;

// Keycodes for keys and assets of the game logic 
enum    e_keycode
{
    KEY_W = 119,
    KEY_A = 97,
    KEY_S = 115,
    KEY_D = 100,
    KEY_ESC = 65307,
};

enum    e_tiles
{
    PLAYER_TILE = 0,
    COLLEC_TILE = 1,
    WALL_TILE = 2,
    FLOOR_TILE = 3,
    EXIT_TILE = 4,
};

enum    e_assets
{
    PLAYER = 'P',
    COLLEC = 'C',
    WALL = '1',
    FLOOR = '0',
    EXIT = 'E',
};

typedef struct s_data
{
    void        *img;
    char        *addr;
    int         height;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}                   t_data; 

typedef struct s_player
{
    t_point     pos;            // Player's current position
    int     moves;              // Number of moves the player has made
}               t_player;

typedef struct s_anim
{
    void        **imgs;
    char        **addrs;
    int         frame_count;
    int         current_frame;
    int         delay;              // Delay between frames in animation
    int         next_frame_time;    // The game time when the next should be
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         width;
    int         height;
}                   t_anim;

/* typedef struct s_enemy
{
    t_point     pos;
    t_point     dir;
    t_anim      anim;
}                   t_enemy; */

typedef struct s_tile
{
    void        *mlx;           // MiniLibX context
    void        *img;           // Image
    char        *addr;          // Image data
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         width;
    int         height;
    int         is_animated;
    t_anim      anim;
}                   t_tile;

/*  Game structure: stores all the necessary information about the game
 *  game state, including the map, the player's position, the number of
 *  collectables, etc. */

typedef struct s_game
{
    void        *mlx;
    void        *win;
    char        **map;          // 2D array representing the map
    int         map_width;      // Width of the map
    int         map_height;     // Height of the map
    t_data      img_data;       // Image data for rendering the game
    t_player    player;         // Player data (position, etc.)
    t_point     exit;
    int         collectibles;   // Number of collectibles left to colect
    int         is_game_over;
    int         time;           // Current game time
    t_tile      tiles[TOTAL_TILES];
    /* struct {
        t_tile  wall;
        t_tile  floor;
        t_tile  player;
        t_tile  collectible;
        t_tile  exit;
    }               tiles; */
}                   t_game;

/*  read_map: takes the filename of the map file and a pointer to a 't_game'
 *  structure. It fills in the 'map', 'map_width', 'map_height', and 'collectibles'
 *  fields of the 't_game' structure based on the contents of the map file. 
 * 
 *  It also finds the player's starting position and initializates the 'player'
 *  field of the 't_game? accordingly. */
int     read_map(char *filename, t_game *game);

int     is_valid_map_character(char c);

/*  my_mlx_pixel_put: ??? */
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

/**/
int     is_valid(t_game *game, t_point point);

/**/
int     is_map_path_valid(t_game *game);

/**/
int     is_map_surrounded_by_walls(t_game *game);

/**/
void    init_game(t_game *game);

/**/
void    *load_xpm(void *mlx_ptr, char *path, int *width, int *height);

/**/
void    render_tile(t_game *game, t_tile tile, int x, int y);

/**/
void    render_anim(t_game *game, t_anim *anim, int x, int y);

/**/
void    render_game(t_game *game);

/**/
int     key_press(int key, t_game *game);

/**/
int     game_loop(t_game *game);

/**/
int     close_game(t_game *game); // or 'cleanup()'

/**/
void    end_game(t_game *game);

#endif
