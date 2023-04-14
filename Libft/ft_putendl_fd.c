/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:11:39 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/22 19:02:28 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putendl_fd(char *s, int fd)
{
	if (!fd)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// TEST
/*int	main(void)
{
	char	str[] = "a little boring test";
	int	fd = 1;

	ft_putendl_fd(str, fd);
	return (0);
}
*/

// DESCRIPTION
/* Outputs the string ’s’ to the given file descriptor
 * followed by a newline.
 */
