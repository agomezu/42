/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:15:12 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 21:16:07 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strchr(const char *s, int c);

char
	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;	
	while ((*s != '\0') && (*s != c))
		s++;
	if (*s == c)
		return ((char*)s);
	else
		return ((char*)NULL);	
}
