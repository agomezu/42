/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:36:31 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/21 12:50:45 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	is_char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1);
	while (is_char_set(s1[start], set))
		++start;
	while (end > start && is_char_set(s1[end - 1], set))
		--end;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + start, end - start + 1);
	return (ptr);
}

// TEST
/* int	main(void)
{
	char	str1[] = "hello world!!! hello";
	char	trim[] = "hello";

	printf("\nRemove \'%s\' from \'%s\'\n", trim, str1);
	printf("Result:\t\t%s\n\n", (char *)ft_strtrim(str1, trim));
	return (0);
}
*/

// DESCRIPTION
/* Allocates (with malloc(3)) and returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 */
