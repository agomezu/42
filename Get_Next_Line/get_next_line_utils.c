/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:07:08 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/16 12:42:08 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

// Funciones auxiliares
// Algunas funciones útiles:
//
// ft_strlen: para calcular la longitud de una cadena de caracteres.
// ft_strchr: para buscar un carácter en una cadena de caracteres.
// ft_strjoin: para unir dos cadenas de caracteres.
// ft_substr: para extraer una subcadena de una cadena de caracteres.
// ft_strdup: para duplicar una cadena de caracteres.

size_t
	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			character;

	i = 0;
	character = (char)c;
	while (s[i])
	{
		if (s[i] == character)
			return ((char *)&s[i]);
		++i;
	}
	if (character == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char
	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s, len);
	return (ptr);
}

char
	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*newstr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (0);
	else
	{
		ft_memcpy(newstr, s1, len1);
		ft_memcpy(newstr + len1, s2, len2);
		newstr[len1 + len2] = '\0';
	}
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
	return (ft_strlen(src));
}

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!*s || !s)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (len == 0)
		return (ft_strdup(""));
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}
