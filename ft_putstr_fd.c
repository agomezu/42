/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:02:00 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:42:40 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putstr_fd(char *s, int fd)
{
	while (*(s))
		write(fd, s++, 1);
}

// TEST
// fcntl.h (file control option) is necessary to compile well 
/* int	main(void)
{
	int	fd;

	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	ft_putstr_fd("STDOUT file descriptor", fd);
	close(fd);
	return (0);
}
*/

// DESCRIPTION
/* Outputs the string ’s’ to the given file
 * descriptor.
 */
