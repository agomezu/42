#include "../includes/so_long.h"

void    parse_line(char *line, int i, t_game *game)
{
    int j;

    j = 0;
    while (line[j])
    {
        if (line[j] == 'C')
            game->collectibles++;
        else if (line[j] == 'E')
            game->exit = (t_point){j, i};   // Set the exit position
        else if (line[j] == 'P')
            game->player = (t_player){(t_point){j, i}, 0};
        j++;
    }
}

int     parse_map(char *filename, t_game *game)
{
    int     fd;
    char    *line;
    int     i;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error: Could not open map file\n", 30);
        return (0);
    }
    i = 0;
    while ((line = get_next_line(fd)) > 0)
    {
        game->map[i] = line;
        if (game->map_width == 0)
            game->map_width = ft_strlen(line);
        else if (game->map_width != ft_strlen(line))
        {
            write(2, "Error: Map is not rectangular\n", 29);
            return (0);
        }
        prase_line(line, i, game);
        i++;
    }
    game->map_height = i;
    close(fd);
    return (1);
}

int     validate_map(t_game *game)
{
    if (!is_map_surrounded_by_walls(game))
    {
        write(2, "Error: Map is not surrounded by walls\n", 37);
        return (0);
    }
    if (!is_map_path_valid(game))
    {
        write(2, "Error: Map does not have a valid path\n", 37);
        return (0);
    }
    return (1);
}

int     read_map(char *filename, t_game *game)
{
    if (!parse_map(filename, game))
        return (0);
    if (validate_map(game))
        return (0);
    return (1);
}