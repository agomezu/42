/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:46:39 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/06 17:10:30 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	
	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*destination;
	unsigned const char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned const char *)src;
	if (n == 0)
		return (destination);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		++i;
	}
	return (destination);
}

// TEST
/* with overleap
int	main(void)
{
	char	src[] = "my name is alejandro";
	char	dst[] = "and my name is block of memory";

	printf("\nOriginal strings:\n");
	printf("------------------------------------------\n");
	printf("\t%s\n", src);
	printf("\t%s\n", dst);
	int	n = 10;
	printf("\n\n\nResult after using memcpy function on the first \033[4m%d\033[0m bytes:", n);
	printf("\n------------------------------------------\n");
	printf("\t%s\n\n\n", (char *)ft_memcpy(dst + 2, dst, n));
	return (0);
}
*/

// DESCRIPTION
/* The memcpy() function copies n bytes from memory area src to memory area dst.
 * If dst and src overlap, behavior is undefined.  Applications in which dst and
 * src might overlap should use memmove(3) instead.
 *
 * The memcpy() function returns the original value of dst.
 */
