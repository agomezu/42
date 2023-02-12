/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/12 21:58:01 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	size_t	i;

	if (!needle)
		return ((char*)haystack);	
	i = 0;
	while (*(haystack) != '\0'  && i < len)
	{
		if (*(haystack) == *(needle))
			return ((char*)needle);
		haystack++;
	}
	return ((char*)NULL);
}

