/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:29:25 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 21:34:18 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *s, int c);

char
	*ft_strrchr(const char *s, int c)
{
	if (!s)
		return (0);
	else
	{
		while (*s != '\0')
			++s;
		while (*s != c)
			--s;
		if (*s == c)
			return ((char*)s);
		else
			return ((char*)NULL);
	}
}
