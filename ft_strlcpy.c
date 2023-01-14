/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:48:13 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/14 14:42:03 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libfth.h"

size_t
	ft_strlcpy(char * dst, const char * src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (*(src + i) && i < (dstsize - 1))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
	}
	while (*(src + i))
		i++;
	return (i);
}		
