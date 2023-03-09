/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:45:53 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:39:20 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return ((int)(p1[i] - p2[i]));
		++i;
	}
	return (0);
}

/* int	main(void)
{
	char	str1[] = "hello, world!";
	char	str2[] = "hello world";
	int	n = ft_strlen(str1);

	printf("Using ft_memcmp with this two strings:\n-> %s\n-> %s\n",
		str1, str2);
	printf("\n\nResult:\t%d\n", ft_memcmp(str1, str2, n));
	return (0);
}
*/

// DESCRIPTION
/* The  memcmp() function compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 *
 * The memcmp() function returns an  integer  less  than,  equal  to,  or
 * greater  than  zero if the first n bytes of s1 is found, respectively,
 * to be less than, to match, or be greater than the first n bytes of s2.
 *
 * For a nonzero return value, the sign is determined by the sign of  the
 * difference  between  the  first pair of bytes (interpreted as unsigned
 * char) that differ in s1 and s2.
 *
 * If n is zero, the return value is zero.
 */
