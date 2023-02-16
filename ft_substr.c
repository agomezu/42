/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:05:38 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/15 20:31:20 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len);

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (i >= start && j < len)
		{
			*(str + j) = *(s + i);
			++j;
		}
		++i;
	}
	*(str + j) = '\0';
	return (str);
}

/*int	main(void)
{
	char	src[] = "honey_";

	printf("The original string is: %s\nAnd the result after ft_substr() is: %s\n", src, ft_substr(src, 1,3));
	return (0);
}*/
