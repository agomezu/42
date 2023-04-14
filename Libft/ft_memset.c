/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:36:02 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/23 15:09:08 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ret;

	i = 0;
	ret = (unsigned char *)b;
	while (i < len)
	{
		ret[i] = c;
		++i;
	}
	return (ret);
}

// MAIN FUNCTION
/*
int	main(void)
{
	unsigned char	str[] = "onetwothreefourfive";
	char	c = 'Z';
	int	n = 4;

	printf("\nOriginal string: %s", str);
	printf("\nString after ft_memset: %s\n", (char*)ft_memset(str, c, n));
	return (0);
}
*/

// DESCRIPTION
/* The memset() function writes len bytes of value c (converted to an unsigned
 * char) to the string b.
 *
 * The memset() function returns its first argument.
 */
