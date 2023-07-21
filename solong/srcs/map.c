#include "../includes/so_long.h"

int     count_lines(char *filename)
{
    int     fd;
    char    *line;
    int     lines_count;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error: Could not open map file\n", 30);
        return (-1);
    }
    lines_count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);
        lines_count++;
    }
    close(fd);
    return (lines_count);
}

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

    game->map_height = count_lines(filename);
    if (game->map_height < 0)
        return (0);
    game->map = (char**)malloc(sizeof(char*) * game->map_height);
    if (!game->map)
    {
        write(2, "Error: Memory allocation failed\n", 32);
        return (-1);
    }
    fd = open (filename, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error: Could not open map file\n", 30);
        return (-1);
    }
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
        if (!game->map[i])
        {
            write(2, "Error: Memory allocation failed\n", 32);
            return (-1);
        }
        ft_strlcpy(game->map[i], line, ft_strlen(line) + 1);
        if (game->map_width == 0)
        {
            game->map_width = ft_strlen(line) - 1;
            // Check error:
            printf("Length of line: %zu\n", ft_strlen(line));
        }
        else if (game->map_width != (int)ft_strlen(line) - 1)
        {
            // Check error:
            printf("Length of line: %zu\n", ft_strlen(line));
            write(2, "Error: Map is not rectangular\n", 29);
            return (-1);
        }
        parse_line(line, i, game);
        free(line);
        i++;
    }
    close(fd);
    return (0);
}

int     validate_map(t_game *game)
{
    if (!is_map_surrounded_by_walls(game))
    {
        write(2, "Error: Map is not surrounded by walls\n", 37);
        return (-1);
    }
    if (!is_map_path_valid(game))
    {
        write(2, "Error: Map does not have a valid path\n", 37);
        return (-1);
    }
    return (0);
}

int     read_map(char *filename, t_game *game)
{
    if (!parse_map(filename, game))
        return (-1);
    if (!validate_map(game))
        return (-1);
    return (0);
}