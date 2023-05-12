/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:07:08 by agomez-u          #+#    #+#             */
/*   Updated: 2023/05/03 19:33:27 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char
	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void
	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		++i;
	}
	return (dst);
}

char
	*ft_strmerge(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*newstr;

	len1 = 0;
	len2 = 0;
	while (s1 && s1[len1])
		++len1;
	while (s2 && s2[len2])
		++len2;
	newstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (0);
	ft_memcpy(newstr, s1, len1);
	if (s2)
		ft_memcpy(newstr + len1, s2, len2);
	newstr[len1 + len2] = '\0';
	return (newstr);
}

size_t
	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = 0;
	}
	i = 0;
	while (src[i])
		++i;
	return (i);
}

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = 0;
	while (s && s[s_len])
		++s_len;
	if (!s || !*s || start > s_len)
		return (ft_strmerge("", NULL));
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
