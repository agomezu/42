/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:36:31 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/24 18:02:42 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_char_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;	
	char	*str;

	if (!s1 || !set)
		return ((char*)s1);
	while (*(s1 + start) && ft_char_in_set(*(s1 + start), set))
	       start++;	
	end = (ft_strlen(s1) - 1);
	while (*(s1 + end) && ft_char_in_set(*(s1 + end), set))
		end--;
	str = (char*)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (0);
	i = 0;
	while (start < end)
	{
		*(str + i) = *(s1 + start++);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
