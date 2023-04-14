/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:29:25 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/22 15:29:48 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

char
	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		--len;
	}
	return (NULL);
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
