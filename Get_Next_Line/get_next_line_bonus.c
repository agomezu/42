/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:19:10 by agomez-u          #+#    #+#             */
/*   Updated: 2023/05/18 14:45:14 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char		*buffer[1024];
	char			*line;
	int				bytes_read;
	int				status;

	line = NULL;
	bytes_read = 1;
	buffer[fd] = handle_buffer(fd, &buffer[fd], &bytes_read);
	if (!buffer[fd])
		return (NULL);
	status = process_buffer(&buffer[fd], &line);
	if (status <= 0)
	{
		free(buffer[fd]);
		free(line);
		buffer[fd] = NULL;
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
	int	fd1 = open("./file1.txt", O_RDONLY);
	int	fd2 = open("./file2.txt", O_RDONLY);
	char	*line = NULL;

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening file(s)");
		return (1);
	}
	int	fd_to_read = fd1; // start with the first file
	while ((line = get_next_line(fd_to_read)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
		// Alternate between the two files
		fd_to_read = (fd_to_read == fd1) ? fd2 : fd1;
	}
	close(fd1);
	close(fd2);
	return (0);
} */

/*
 *  File: get_next_line_bonus.c
 * 
 *  The file defines a set of functions that enables reading from multiple
 *  file descriptors line by line in a memory-efficient manner. This 
 *  enhanced functionality is achieved through the use of an array of 
 *  static buffers.
 * 
 *  The primary function is 'get_next_line', which reads from the specified 
 *  file descriptor 'fd' into the corresponding buffer, and then copies a 
 *  line from the buffer into 'line'. A "line" is considered a sequence of 
 *  characters ending with '\n' or the end of the file.
 * 
 *  The 'handle_buffer' and 'read_buffer' are helper functions that read 
 *  data from the file into the buffer and handle buffer operations 
 *  respectively. 'process_buffer' is a function responsible for processing 
 *  the buffer's contents, copying lines from it when needed.
 * 
 *  It's important to note that the code uses a set of string utility 
 *  functions ('ft_substr', 'ft_strchr', and 'ft_strmerge'), which aren't 
 *  defined in this file. These functions should be properly defined 
 *  elsewhere in your code.
 * 
 *  The implementation uses the BUFFER_SIZE macro, which should be defined 
 *  before this file is included. BUFFER_SIZE is typically set to a value 
 *  that offers a balance between memory usage and the number of system 
 *  calls made.
 * 
 *  Care has been taken to manage memory in the code to prevent leaks. 
 *  However, ensure to call 'free' on the string returned by 
 *  'get_next_line' when you are done with it.
 * 
 *  Error handling: In case of an error, functions will return NULL or -1 
 *  as appropriate, and any allocated memory is freed. 
 * 
 *  This is a bonus version of the 'get_next_line' function which supports 
 *  multiple file descriptors concurrently.
 */
