/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:08:57 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/15 23:44:51 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin(char const *s1, char const *s2);

char
	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	int	len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	//printf("\nTotal length:\t%d\n", len);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (*(s1 + j))
	{
		*(char*)(str + i) = *(char*)(s1 + j);
		++i;
		++j;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(char*)(str + i) = *(char*)(s2 + j);
		++i;
		++j;
	}
	*(str + i) = '\0';
	return (str);
}       
/*
int	main(void)
{
	char	s1[] = "AAA lllll";
	char	s2[] = "zzzAAAA___&&&";
	char	*sum = ft_strjoin(s1, s2);

	printf("The sum of:\t%s\nAnd:\t\t%s\nIs:\t\t%s\n___________________\n"
			, s1, s2, sum);
	return (0);
}*/
