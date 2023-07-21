#include "../includes/so_long.h"

int     is_map_surrounded_by_walls(t_game *game)
{
    int i;
    int j;

    for (j = 0; j < game->map_width; j++)
    {
        if (game->map[0][j] != '1' || game->map[game->map_height - 1][j] != '1')
            return (0);
    }
    for (i = 0; i < game->map_height; i++)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
            return (0);
    }
    return (1);
}

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
    if (visited[point.y * width + point.x])
        return (1);
    return (0);
}

void    dfs(t_game *game, int *visited, t_point point, int width)
{
    t_point     directions[4] = {(t_point){0, 1}, (t_point){1, 0}, (t_point){0, -1}, (t_point){-1, 0}};
    t_point     next;
    int         i;

    visited[point.y * width + point.x] = 1;
    // Recursively visit all unvisited neighbors
    for (i = 0; i < 4; i++)
    {
        next.x = point.x + directions[i].x;
        next.y = point.y + directions[i].y;
        if (is_valid(game, next) && !is_visited(visited, next, width))
            dfs(game, visited, next, width);
    }
}

int     is_map_path_valid(t_game *game)
{
    int     *visited;
    int     result;

    visited = (int *)ft_calloc(game->map_height * game->map_width, sizeof(int));
    if (!visited)
        return (0);
    dfs(game, visited, game->player.pos, game->map_width);
    result = is_visited(visited, game->exit, game->map_width);
    free(visited);
    return (result);
}

