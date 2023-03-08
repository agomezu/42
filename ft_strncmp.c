/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:35:06 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:39:00 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && (i < n) && (*(s1 + i) && *(s2 + i)))
	{
		if (*(s1 + i) != *(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
