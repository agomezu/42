/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 15:22:02 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int	main(void)
{
	char	s1[] = "www";
	char	s2[] = "ywwwhellowww";
	char	*r = ft_strnstr(s2, s1, 9);
	
	printf("%s\n", r);
	return (0);
}

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*(needle) == '\n')
		return ((char *)haystack);	
	i = 0;
	while (*(haystack + i) && ((size_t)i < len))
	{
		if (*(haystack + i) == *(needle + 0))
		{
			j = 0;
			while ((*(haystack + (i + j)) == *(needle + j)) && i + j < len)
			{
				if (*(needle + (j + 1)) == 0)
					//
					return	((char*)haystack + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
