/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:07:24 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 19:41:38 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void
	*ft_memchr(const void *s, int c, size_t n);

/*
int	main(void)
{
	char	str[] = "https://www.something.nothing";
	char	a = 'w';
	char	*r = (char*)ft_memchr(str, a, 30);
	printf("%c\n", *r);
	return (0);
}
comment: need to rewrite this. i have some obstacles at the time of understanding the use of
pointers, specifiers and more. main() function using the type void* memchr.
*/

void
	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*str;
	unsigned char	to_find;

	i = 0;
	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (i < n)
	{
		if (*(str + i) == to_find)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
