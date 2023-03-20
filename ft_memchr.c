/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:07:24 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/20 22:10:23 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// TEST
/* int	main(void)
{
	char	str[] = "The string to search for the character";
	char	c = 'o';

	printf("%s is %c\n", str, c);
	printf("Let's search through ft_memchr()...\n\n");
	if (ft_memchr(str, c, ft_strlen(str)))
	{
		printf("Result:\t\t%s\n",
			(char *)ft_memchr(str, c, ft_strlen(str)));
	}
	else
		printf("Sorry, not found...\n");
	return (0);
}
*/

// DESCRIPTION
/* The  memchr()  function  scans  the initial n bytes of the memory area
 * pointed to by s for the first instance of c.  Both c and the bytes  of
 * the memory area pointed to by s are interpreted as unsigned char.
 *
 * The  memchr() and memrchr() functions return a pointer to the matching
 * byte or NULL if the character does not occur in the given memory area.
 */
