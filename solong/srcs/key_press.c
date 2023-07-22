#include "../includes/so_long.h"

void    move_player(t_game *game, t_point direction)
{
    t_point     new_pos;

    if (game->is_game_over)
        return ;
    // Calculate the player's new position
    new_pos.x = game->player.pos.x + direction.x;
    new_pos.y = game->player.pos.y + direction.y;
    // Check if the new position is valid (not a wall and within the map bounds)
    if (new_pos.x < 0 || new_pos.x >= game->map_width ||
        new_pos.y < 0 || new_pos.y >= game->map_height ||
        game->map[new_pos.y][new_pos.x] == WALL)
        return ;
    // Check for collectibles 
    if (game->map[new_pos.y][new_pos.x] == COLLEC)
    {
        game->collectibles--;
        game->map[new_pos.y][new_pos.x] = FLOOR;
    } 
    // Check for exit
    if (game->map[new_pos.y][new_pos.x] == EXIT &&
        game->collectibles == 0) 
        end_game(game);
    // Render floor at old player position
    render_tile(game, game->tiles.floor,
                game->player.pos.x, game->player.pos.y); 
    // Update player's position
    game->player.pos = new_pos;
    game->player.moves++;
    // Render player at new position
    render_anim(game, &game->tiles.player.anim,
                game->player.pos.x, game->player.pos.y);
    render_game(game);
}

int     key_press(int key, t_game *game)
{
    t_point     direction;

    direction.x = 0;
    direction.y = 0;
    // Up
    if (key == KEY_W)
        direction.y = -1;
    // Left
    else if (key == KEY_A)
        direction.x = -1;
    // Down
    else if (key == KEY_S)
        direction.y = 1;
    // Right
    else if (key == KEY_D)
        direction.x = 1; 
    else if (key == KEY_ESC)
        close_game(game);
    move_player(game, direction);
    return (0);
}