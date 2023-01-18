/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:48:21 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 20:54:25 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memmove(void *dst, const void *src, size_t len);

void	
	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	else
	{
		i = 0;
		j = ft_strlen(dst);	
		
		while (i < len)
			*(char*)(dst + j++) = *(char*)(src + i++);
	}
	return (dst);
}
