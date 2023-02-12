/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/12 22:21:13 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	size_t	i;
	size_t	j;

	if (*(needle + 0) == '\0')
		return ((char*)haystack);	
	i = 0;
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(haystack + i) != *(needle + j) && *(needle + j))
			j++;
		if (*(haystack + i) == *(needle + j))
			return ((char*)(haystack + i));
		i++;
	}
	return ((char*)NULL);
}
