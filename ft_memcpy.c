/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:46:39 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/22 20:33:35 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	
	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		++i;
	}
	return (dst);
}

/* TEST
int	main(void)
{
	char	src[] = "my name is alejandro";
	char	dst[] = "and my name is block of memory";

	printf("\nOriginal strings:\n");
	printf("------------------------------------------\n");
	printf("\t%s\n", src);
	printf("\t%s\n", dst);
	int	n = 10;
	printf("\n\n\nResult after using memcpy function on the first"
       		"\033[4m%d\033[0m bytes:", n);
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
