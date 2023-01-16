/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 20:32:51 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*strnstr(const char *haystack, const char *needle, size_t len);

char
	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	unsigned const char	*s1;
	unsigned const char	*s2;

	if (!needle)
		return (haystack);
	else
	{
		i = 0;
		s1 = (unsigned const char *)haystack;
		s2 = (unsigned const char *)needle;
		while (i < len)
		{
			if (*(s1 + i) != *(s2 + i))
				continue ;
			else
				break ;
		i++;
		}
		if (*(s2 + i) == 0)
			return (0);
		else if ((*(s1 + i) == *(s2 + i)) && i < len)
			return (*(s2 + i));
	}
	return (0);
}
