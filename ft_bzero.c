/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:42:36 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 20:46:18 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_bzero(void *s, size_t n);

void
	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	else
	{
		while (i < n)
		{
			*(char*)(s + i) = 0;
			i++
		}
	}
}
