/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:46 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/16 13:06:09 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

static int
	read_buffer(int fd, char **buffer)
{
	// Leer del file descriptor y almacenar en el buffer
	// Devolver el número de bytes leídos

	ssize_t	bytes_read;
	char	temp_buffer[BUFFER_SIZE + 1];
	char	*tmp;

	if (fd < 0 || !buffer)
		return (0);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	temp_buffer[bytes_read] = '\0';
	if (*buffer == NULL)
		*buffer = ft_strdup(temp_buffer);
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
		*buffer = NULL;
		return (0);
	}
}

char
	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int		status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = 1;
	while (status == 1)
	{
		if (!buffer || !ft_strchr(buffer, '\n'))
			status = read_buffer(fd, &buffer);
		if (status < 0)
			return (NULL);
		status = process_buffer(&buffer, &line);
	}
	if (status == 0)
		return (NULL);
	else
		return (line);
}
