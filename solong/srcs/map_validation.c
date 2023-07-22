#include "../includes/so_long.h"

/* Map checker for surrounding walls */
int     is_valid_map_character(char c)
{
    return (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E');
}

int     is_map_surrounded_by_walls(t_game *game)
{
    int i;
    int j;

    printf("Entering is_map_surrounded_by_walls...\n");
    // Check top and bottom rows
    j = 0;
    while (j < game->map_width)
    {
        if (game->map[0][j] != '1' || game->map[game->map_height - 1][j] != '1'
            || !is_valid_map_character(game->map[0][j])
            || !is_valid_map_character(game->map[game->map_height - 1][j]))
            return (0);
        j++;
    }
    printf("Top and bottom rows OK\n");
    // Check left and right columns
    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1'
            || !is_valid_map_character(game->map[i][0])
            || !is_valid_map_character(game->map[i][game->map_width -1]))
            return (0);
        i++;
    }
    printf("Left and right columns OK\n");
    return (1);
}

/***************************************/
/* DEAPTH-FIRST SEARCH: for valid path */
/* Must study this part more to deepen */

int     is_valid(t_game *game, t_point point)
{
    if (point.x >= 0 && point.x < game->map_width &&
        point.y >= 0 && point.y < game->map_height &&
        game->map[point.y][point.x] != '1')
            return (1);
    return (0);
}

int     is_visited(int *visited, t_point point, int width)
{
    return (visited[point.y * width + point.x]);
}

int     dfs(t_game *game, int *visited, t_point point, int width)
{
    t_point     directions[4] = {(t_point){0, 1},
                                 (t_point){1, 0},
                                 (t_point){0, -1},
                                 (t_point){-1, 0}};
    t_point     next;
    int         i;

    // If we reached the exit, return true 
    if (point.x == game->exit.x && point.y == game->exit.y)
        return (1);
    visited[point.y * width + point.x] = 1;
    // Recursively visit all unvisited neighbors
    for (i = 0; i < 4; i++)
    {
        next.x = point.x + directions[i].x;
        next.y = point.y + directions[i].y;
        if (is_valid(game, next) && !is_visited(visited, next, width))
        {
            if (dfs(game, visited, next, width))
                return (1);
        }
    }
    return (0); // If we explored all possible paths and didn't find the exit, return false
}

int     is_map_path_valid(t_game *game)
{
    int     *visited;
    int     result;

    visited = (int *)ft_calloc(game->map_height * game->map_width, sizeof(int));
    if (!visited)
        return (0);
    result = dfs(game, visited, game->player.pos, game->map_width); 
    free(visited);
    return (result);
}

