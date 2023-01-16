/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:45:53 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 20:15:32 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int
	memcmp(const void *s1, const void *s2, size_t n);

int
	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while ((*(str1 + i) && *(str2 + i)) && i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*(str1 + i) - *(str2 + i));
		i++;
	}
	return (0);
}