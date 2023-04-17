/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:46 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/17 08:14:06 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include "get_next_line.h"

static int
	read_buffer(int fd, char **buffer)
{
	// Leer del file descriptor y almacenar en el buffer
	// Devolver el número de bytes leídos

	ssize_t	bytes_read;
	char	temp_buffer[BUFFER_SIZE + 1];
	char	*tmp;

	// if (fd < 0 || !buffer)
		// return (0);	
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

	// if (!buffer || !*buffer || !line)
		// return (-1);
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

int
	get_next_line(int fd, char **line)
{
	static char	*buffer = NULL;
	int		bytes_read;
	int		ret;

	if (!line)
		return (-1);

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
		return (-1);
	}
	if (buffer == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	ret = process_buffer(&buffer, line);
	if (ret == 0 && line != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	return (ret);
}

int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);
	char	*line = NULL;
	int	ret = 0;

	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	
	if (ret == 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	else
		perror("Error al leer el archivo");

	close(fd);
	return (0);
}
