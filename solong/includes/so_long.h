#ifndef SO_LONG_H
# define SO_LONG

#include <fcntl.h>
#include <unistd.h>
#include "minilibx_linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

/* Size of every sprite */
#define TILE_SIZE 32 

/* A simple structure that represents a point in 2D space */
typedef struct s_point
{
    int         x;
    int         y;
}                   t_point;

typedef enum e_tiletype
{
    EMPTY = '0';
    WALL = '1';
    COLLECTABLE = 'C';
    PLAYER = 'P';
    EXIT = 'E';
}                   t_tiletype;

// Keycodes
enum    e_keycode
{
    KEY_W = 119;
    KEY_A = 97;
    KEY_S = 115;
    KEY_D = 100;
    KEY_ESC = 65307;
};

typedef struct s_tile
{
    void        *img;           // Image
    char        **addr;         // Image data
    int         width;          // W of the image
    int         height;         // H of the image
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
    struct {
        t_tile  wall;
        t_tile  floor;
        t_tile  player;
        t_tile  collectible;
        t_tile  exit;
    }               tiles;
}                   t_game;

typedef struct s_player
{
    t_point     pos;            // Player's current position
    int     moves;              // Number of moves the player has made
}               t_player;

typedef struct s_data
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

/*  read_map: takes the filename of the map file and a pointer to a 't_game'
 *  structure. It fills in the 'map', 'map_width', 'map_height', and 'collectibles'
 *  fields of the 't_game' structure based on the contents of the map file. 
 * 
 *  It also finds the player's starting position and initializates the 'player'
 *  field of the 't_game? accordingly. */
int     read_map(char *filename, t_game *game);

/*  my_mlx_pixel_put: ??? */
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

/**/
int     is_valid(t_game *game, t_point point);

/**/
int     is_map_path_valid(t_game *game);

/**/
int     is_map_surrounded_by_walls(t_game *game);

/**/
void    init_game(t_game *game)

/**/
void render_game(t_game *game)

/**/
int     key_press(int keycode, t_game *game);

#endif