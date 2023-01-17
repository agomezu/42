/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/17 19:38:28 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int	main(void)
{
	char	s1[] = "www";
	char	s2[] = "https://www.hello.www";

	printf("%s\n", ft_strnstr(s2, s1, 30));
	return (0);
}

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*(needle + i) == 0)
		return ((char *)haystack);	
	while (*(haystack + i) && (i < len))
	{
		if (*(haystack + i) == *(needle + j))
		{
		}
		i++;
	}
	if ((*(s1 + i) == *(s2 + i)) && i < len)
		return ((char*)(s2 + i));
	else
		return (0);
	}
	return (0);
}
