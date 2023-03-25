/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:30:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:41:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	ft_count(char const *s, char sep)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			counter++;
		while (*s && *s != sep)
			s++;
	}
	return (counter);
}

char
	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!lst)
		return (0);
	i = 0;
	while (*(s))
	{
		while (*s == c && *s)
			++s;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			*(lst + i++) = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	*(lst + i) = 0;
	return (lst);
}
