/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 07:42:31 by agomez-u         ###   ########.fr       */
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
	char	*hay;

	if (*(needle + 0) == '\0' || haystack == needle)
		return ((char *)haystack);
	i = 0;
	hay = (char *)haystack;
	while (*(hay + i) && i < len)
	{
		j = 0;
		while (*(hay + i + j) != '\0' && *(needle + j) != '\0' && \
				*(hay + i + j) == *(needle + j) && i + j < len)
			++j;
		if (j == ft_strlen(needle) && i + j <= len)
			return ((char *)(hay + i));
		++i;
	}
	return ((char *) NULL);
}
