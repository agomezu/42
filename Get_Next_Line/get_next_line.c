/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:46 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/14 15:15:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

static int
	read_buffer(int fd, char **buffer)
{
	// Leer del file descriptor y almacenar en el buffer
	// Devolver el número de bytes leídos
}

static int
	process_buffer(char **buffer, char **line)
{
	// Procesar el contenido del buffer
	// Extraer una línea completa del buffer y almacenar en la variable 'line'
	// Devolver 1 si se encuentra una línea completa, 0 si se llega al final del archivo, -1 si hay un error
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

	return (status == 0 ? NULL : line);
}
