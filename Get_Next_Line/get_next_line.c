/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:46 by agomez-u          #+#    #+#             */
/*   Updated: 2023/05/12 12:28:00 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <fcntl.h>

static int
	read_buffer(int fd, char **buffer)
{
	ssize_t	bytes_read;
	char	temp_buffer[BUFFER_SIZE + 1];
	char	*tmp;

	if (fd < 0 || !buffer)
		return (0);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);	
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0)
		return (0);
	temp_buffer[bytes_read] = '\0';
	if (*buffer == NULL)
		*buffer = ft_substr(temp_buffer, 0, bytes_read);
	else
	{
		tmp = ft_strjoin(*buffer, temp_buffer);
		free(*buffer);
		*buffer = tmp;
	}
	return (bytes_read);
}

static int
	process_buffer(char **buffer, char **line)
{
	char	*newline;
	char	*tmp;

	if (!buffer || !*buffer || !line)
		return (-1);
	newline = ft_strchr(*buffer, '\n');
	if (newline != NULL)
	{
		*line = ft_substr(*buffer, 0, newline - *buffer + 1);
		tmp = ft_strdup(newline + 1);
		free(*buffer);
		*buffer = tmp;
		if (!*line || !*buffer)
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		if (!*line)
			return (-1);
		return (*line != NULL);
	}
}

char
	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	int		bytes_read;
	char		*line = NULL;
	int		status;

	if (fd < 0)
		return (NULL);
	while (buffer == NULL || ft_strchr(buffer, '\n') == NULL)
	{
		bytes_read = read_buffer(fd, &buffer);
		if (bytes_read <= 0)
			break ;
	}
	if (bytes_read < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	status = process_buffer(&buffer, &line);	
	if (status <= 0)
	{
		free(buffer);
		free(line);
		buffer = NULL;
		line = NULL;
		return (0);
	}
	else if (status && line[0] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

/* int	main(void)
{
	int	fd = open("./multiple_nlx5.txt", O_RDONLY);
	char	*line = NULL;

	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
} */
