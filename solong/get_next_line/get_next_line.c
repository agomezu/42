/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:08:46 by agomez-u          #+#    #+#             */
/*   Updated: 2023/05/18 14:36:29 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
		tmp = ft_strmerge(*buffer, temp_buffer);
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
		tmp = ft_strmerge(newline + 1, NULL);
		free(*buffer);
		*buffer = tmp;
		if (!*line || !*buffer)
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strmerge(*buffer, NULL);
		free(*buffer);
		*buffer = NULL;
		if (!*line)
			return (-1);
		return (*line != NULL);
	}
}

char
	*handle_buffer(int fd, char **buffer, int *bytes_read)
{
	if (fd < 0)
		return (NULL);
	while (*buffer == NULL || ft_strchr(*buffer, '\n') == NULL)
	{
		*bytes_read = read_buffer(fd, buffer);
		if (*bytes_read <= 0)
			break ;
	}
	if (*bytes_read < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (*buffer);
}

char
	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*line;
	int				bytes_read;
	int				status;

	line = NULL;
	bytes_read = 1;
	buffer = handle_buffer(fd, &buffer, &bytes_read);
	if (!buffer)
		return (NULL);
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
	int	fd = open("./file.txt", O_RDONLY);
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

/*
 *  File: get_next_line.c
 * 
 *  This file defines a set of functions that collectively read a file 
 *  one line at a time, in a memory-efficient manner.
 * 
 *  The core function is 'get_next_line', which uses a static buffer to 
 *  store the contents of the file. It reads from the file descriptor 'fd' 
 *  into this buffer, and then copies a line from the buffer into 'line', 
 *  where a "line" is defined as a sequence of characters ending with '\n' 
 *  or the end of the file.
 * 
 *  'handle_buffer' and 'read_buffer' are helper functions used to read 
 *  data from the file into the buffer and handle buffer operations. The 
 *  'process_buffer' function processes the contents of the buffer, copying 
 *  lines out of it as needed.
 * 
 *  Note that these functions use a number of string utilities such as 
 *  'ft_substr', 'ft_strchr', and 'ft_strmerge', which are not defined in 
 *  this file. Ensure these functions are properly defined elsewhere in your 
 *  code.
 * 
 *  Also, be aware that this implementation uses the BUFFER_SIZE macro, 
 *  which should be defined before this file is included. Typically, 
 *  BUFFER_SIZE is set to a value that is a trade-off between memory usage 
 *  and the number of system calls made.
 * 
 *  Memory management is carefully handled in the code to prevent leaks. 
 *  Remember to call 'free' on the string returned by 'get_next_line' 
 *  when you are finished with it.
 *
 *  Error handling: In case of an error, functions will return NULL or -1 
 *  as appropriate, and any allocated memory is freed.
 */
