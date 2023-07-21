/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:15:12 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/23 14:51:24 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	const char		*string;
	char			character;

	i = 0;
	string = s;
	character = (char)c;
	while (string[i])
	{
		if (string[i] == character)
			return ((char *)&string[i]);
		++i;
	}
	if (character == string[i])
		return ((char *)&string[i]);
	return (NULL);
}

// TEST
/* int	main(void)
{
	int	c = 'r';
	const char	s[] = "this is a string varrr";	

	printf("\n... We're trying to find %c on -> %s\n",
		c, s);
	printf("\n!! Found at:\t%s\n\n", ft_strchr(s, c));
	return (0);
}
*/

// DESCRIPTION
/* The strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
 *
 * Here  "character"  means "byte"; these functions do not work with wide
 * or multibyte characters.
 *
 * The strchr() and strrchr() functions return a pointer to  the  matched
 * character or NULL if the character is not found.  The terminating null
 * byte is considered part of the string, so that if c  is  specified  as
 * '\0', these functions return a pointer to the terminator.
 */
