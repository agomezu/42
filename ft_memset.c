/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:36:02 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 20:42:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memset(void *b, int c, size_t len);
void
	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (0);
	i = 0;
	while ( i < len )
	{
		*(unsigned char*)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
