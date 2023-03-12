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
	ft_count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s && *s != sep)
			s++;
	}
	return (count);
}

char
	**ft_split(char const *s, char c)
{
	int		i;
	char	**newarr;
	char	*string;
	size_t	next_word_len;
	int	words;

	if (s)
		string = (char *)s;
	else
		return (0);
	words = ft_count_words(string, c);
	newarr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!newarr)
		return (0);
	i = 0;
	while (*(s))
	{
		while (*s == c && *s)
			++s;
		if (*s)
		{
			if (!ft_strchr(s, c))
				next_word_len = ft_strlen(s);
			else
				next_word_len = ft_strchr(s, c) - s;
			*(newarr + i++) = ft_substr(s, 0, next_word_len);
			s += next_word_len;
		}
	}
	*(newarr + i) = 0;
	return (newarr);
}

// TEST
int	main(void)
{
	char	str[] = "this is the string to be splitted";
	char	c = ' ';
	int	i = 0;

	printf("%s\ninto \'%c\'\n\n", str, c);
	char	**ptr = ft_split(str, c);
	while (ptr[i])
	{
		printf("\n\n%s\n\n", ptr[i]);
		++i;
	}
	return (0);
}

// DESCRIPTION
/* Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
 */
