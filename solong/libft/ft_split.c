/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:30:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/23 18:13:20 by agomez-u         ###   ########.fr       */
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

void
	*del_newarr(char **newarr, int i)
{
	while (i--)
		free(newarr[i]);
	free(newarr);
	return (NULL);
}

size_t
	get_next_word_len(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

char
	**ft_split(char const *s, char c)
{
	int		i;
	char	**newarr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	newarr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!newarr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			newarr[i] = ft_substr(s, 0, get_next_word_len(s, c));
			if (!newarr[i++])
				return (del_newarr(newarr, i));
			s += ft_strlen(newarr[i - 1]);
		}
		else
			s++;
	}
	newarr[i] = 0;
	return (newarr);
}

// TEST
/*int	main(void)
{
	// string to be splitted
	char	str[] = "this is the string to be splitted";
	// split character
	char	c = ' ';
	// index var to print every ARRAY OF POINTERS to char
	int	i = 0;

	printf("\n-> %s\ninto -> \'%c\'\n\n", str, c);
	printf("---------------------------------");
	char	**ptr = ft_split(str, c);
	while (ptr[i])
	{
		printf("\n%s\n", ptr[i]);
		++i;
	}
	printf("---------------------------------\n");
	free(ptr);
	return (0);
}
*/

// DESCRIPTION
/* Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
 *
 * Using a char pointer allows you to allocate
 * memory dinamically, which means you can allocate
 * memory for a string of any size at runtime.
 *
 * ft_split allocates memory for an array of pointers
 * to char (char **newarr) using malloc, based on 
 * the number of words counted. Since each element
 * of this array is a pointer to char, it is necessary
 * to allocate memory dynamically for each element
 * of this array.
 *
 * In the while loop that follows, ft_split iterates
 * through the input string again and fills
 * the allocated memory for each element of 'newarr'
 * with a dynamically allocated string using
 * 'ft_substr'.
 *
 * This dynamically allocated string is then assigned
 * to the corresponding element of 'newarr'.
 *
 * Finally, ft_split sets the last element of 'newarr'
 * to NULL to indicate the end of the array.
 *
 * This approach allows for the allocation of memory
 * for each string dynamically, based on its size,
 * and also allows for the creation of an array
 * of strings, which can be accessed later in
 * the program.
 */
