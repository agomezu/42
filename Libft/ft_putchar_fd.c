/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:45:21 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:42:24 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// TEST
/*int	main(void)
{
	char	c;
	int	fd;

	c = 'a';
	fd = 1;
	ft_putchar_fd(c, fd);
	return (0);
}
*/

// DESCRIPTION
/* Outputs the character ’c’ to the given file
 * descriptor.
 *
 * With the external function 'write'.
 *
 * c: The character to output.
 * fd: The file descriptor on which to write.
 *
 * No return.
 */
