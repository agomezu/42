/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:46 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/28 21:05:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include "get_next_line.h"

static int
	read_buffer(int fd, char **buffer)
{
	// reads the fd and saves into buffer variable; then returns total bytes read 
	ssize_t	bytes_read;
	char	temp_buffer[BUFFER_SIZE + 1];
	char	*tmp;

	if (fd < 0 || !buffer)
		return (0);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);	
	if (bytes_read < 0)
		return (-1);
	temp_buffer[bytes_read] = '\0';
	if (bytes_read == 0)
		return (0);
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
	// Procesar el contenido del buffer
	// Extraer una línea completa del buffer y almacenar en la variable 'line'
	// Devolver 1 si se encuentra una línea completa, 0 si se llega al final del archivo, -1 si hay un error
	char	*newline;
	char	*tmp;

	if (!buffer || !*buffer || !line)
		return (-1);
	newline = ft_strchr(*buffer, '\n');
	if (newline != NULL)
	{
		*line = ft_substr(*buffer, 0, newline - *buffer);
		tmp = ft_strdup(newline + 1);
		free(*buffer);
		*buffer = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = ft_strdup("");
		return (0);
	}
}

char
	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	int		bytes_read;
	char		*line = NULL;
	int		status;

	while (buffer == NULL || !ft_strchr(buffer, '\n'))
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
	if (buffer == NULL)
		buffer = ft_strdup("");
	status = process_buffer(&buffer, &line);
	if (status == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	if (line[0] == '\0' && status != 0)
	{
		free(line);
		return (ft_strdup("\n"));	// Return an allocated empty string
	}
	else if (line[0] == '\0' && status == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);
	char	*line = NULL;

	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	
	close(fd);
	return (0);
}
