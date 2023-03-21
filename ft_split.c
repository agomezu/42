/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:30:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/21 18:48:06 by agomez-u         ###   ########.fr       */
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
	del_newarr(char **newarr, int i)
{
	while (i-- > 0)
		free(newarr[i]);
	free(newarr);
}

char
	**ft_split(char const *s, char c)
{
	int		i;
	char	**newarr;
	char	*string;
	size_t	next_word_len;
	int	words;

	if (s == NULL)
		return (0);
	string = (char *)s;
	words = ft_count_words(string, c);
	newarr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!newarr)
		return (0);
	i = 0;
	while (*(string))
	{
		while (*string == c)
			string++;
		if (*string)
		{
			if (ft_strchr(string, c) == NULL)
				next_word_len = ft_strlen(string);
			else
				next_word_len = (ft_strchr(string, c) - string);
			newarr[i++] = ft_substr(string, 0, next_word_len);
			if (newarr[i - 1] == NULL)
			{
				del_newarr(newarr, i);
				return (NULL);
			}
			string += next_word_len;
		}
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
