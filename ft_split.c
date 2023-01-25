/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:30:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/25 20:40:00 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	ft_allocate(char **res, char const *s, char sep);

static int
	ft_count_words(char const *s, char sep);

char
	**ft_split(char const *s, char c);

static void
	ft_allocate(char **res, char const *s, char sep)
{
	char	**res_p;
	char const	*tmp;

	tmp = s;
	res_p = res;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;	
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*res_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++res_p;
		}
	}
	res_p = 0;
}	

static int
	ft_count_words(char const *s, char sep)
{
	int	count;

	count = 0;	
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++count;
		while (*s && *s != sep)
			++s;
	}
	return (count);
}

char
	**ft_split(char const *s, char c)
{
	char	**new;
	int	size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
