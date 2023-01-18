/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:04:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 21:05:07 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t len;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	len = i + j;

	if (dstsize < 1)
		return (len);	
	i = 0;
	while (j < dstsize)	
		*(char*)(dst + j++) = *(char*)(src + i++);
	*(dst + ++j) = 0;
	return (len);
}
