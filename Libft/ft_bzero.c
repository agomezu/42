/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:42:36 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/06 14:58:14 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

// TEST
/*
int	main(void)
{
	char	str[] = "0123456789";
	int	n = 10;

	printf("\nOriginal string: %s", str);
	ft_bzero(str, n);
	printf("\n\n\nString after bzero function: %s\n", str);
	printf("\n\nIf the function is correct\nit will display NOTHING!\n");
	return (0);
}
*/

// DESCRIPTION
/* The bzero() function writes n zeroed bytes to the string s.  If n is zero,
 * bzero() does nothing.
 */
