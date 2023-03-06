/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:48:21 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/06 17:24:42 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	
	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*destination;
	const char	*source;

	destination = (char *)dst;
	source = (char *)src;
	if (destination > source)
		while (len--)
			destination[len] = source[len];
	else
		ft_memcpy(destination, source, len);
	return (destination);
}

// TEST
/*
int	main(void)
{
	char	source[] = "may this piece of string overlap?";
	char	destination[] = "this is the dst var for the ft";

	printf("\n%s\n", (char *)ft_memmove(source + 2, source, 9));
	return (0);
}
*/

// DESCRIPTION
/* The memmove() function copies len bytes from string src to string dst.  The
 * two strings may overlap; the copy is always done in a non-destructive manner.
 *
 * The memmove() function returns the original value of dst.
 */
