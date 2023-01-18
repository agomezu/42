/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:45:53 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 22:37:26 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int
	ft_memcmp(const void *s1, const void *s2, size_t n);

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(unsigned char*)(str1 + i) && *(unsigned char*)(str2 + i) && i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return (*(str1 + i) - *(str2 + i));
		i++;
	}
	return (0);
}
