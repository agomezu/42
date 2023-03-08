/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:29:25 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 18:08:03 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *s, int c);

char
	*ft_strrchr(const char *s, int c)
{
	const char	*string;
	char	character;
	char	*ret;
	int		i;

	string = (const char *)s;
	character = (char)c;
	ret = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == character)
			ret = (char *)&string[i];
		++i;
	}
	if (character == '\0')
		return ((char *)&string[i]);
	else if (ret)
		return ((char *)ret);
	else
		return ((char *) NULL);
}

// TEST
/* int	main(void)
{
	char	c = 'z';
	char	str[] = "abcdefgzzzzvw";

	printf("\nWe're trying to find -> %c on -> %s\n\n", c, str);
	printf("Using ft_strrchr()...\n\n");
	printf("Result:\t\t%s\n\n", ft_strrchr(str, c));
	return (0);
}
*/

// DESCRIPTION
/* The strrchr() function returns a pointer to the last occurrence of the
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
