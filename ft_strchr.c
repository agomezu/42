/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:15:12 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 08:15:13 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int	main(void)
{
	const char	str[] = "i'm coding too late";
	const char	a[] = "i";
	char	*ret;

	ret = ft_strchr(str, (int)a);
	printf("%s\n", ft_strchr(str, ret));
	return (0);
}

char
	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if ((s + i) == (char)c)
		{
			return ((char*)(s + i));
		}	
		++i;
	}
	if ((s + i) == (char)(c))
		return ((char*)(s + i));
	return (0);
}

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *)s);
	}
	return ((char*)NULL);
}
