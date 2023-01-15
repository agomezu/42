/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:04:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/14 23:04:48 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char * dst, const char * src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t len;

	i = 0;
	j = 0;
	
	while (*(src + i))
		i++;
	while (*(dst + j))
		j++;
	len = i + j;

	if (dstsize < 1)
		return (len);
	
	i = 0;
	while (j < dstsize)
	{
		
		*(dst + j) = *(src + i);
		j++;
		i++;
	}
	++j;
	*(dst + j) = 0;
	return (len);
}

/*
int	main(void)
{
	char str1[] = ", machine";
	char str2[] = "it's nice to see you";
	int	n;

	n = 33;
	printf("%zu\t", ft_strlcat(str2, str1, n)); 
	printf("%s\n", str2);
	
	return (0);
}
*/
