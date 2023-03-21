/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:15 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/21 17:58:10 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	size_t	i;
	size_t	j;
	char	*hay;
	char	*need;

	if (!*needle || haystack == needle)
		return ((char *)haystack);
	i = 0;
	hay = (char *)haystack;
	need = (char *)needle;
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i+j] && need[j] && hay[i+j] == need[j] && i+j < len)
			++j;
		if (j == ft_strlen(need) && i + j <= len)
			return (&hay[i]);
		++i;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*big = "bigstreamofloveandpeace";
	char	*little = "stream";
	int	len = ft_strlen(big);

	printf("In this case we're going to use ft_strnstr().\n");
	printf("The strings of the function are this:\n"
		"Big:\t\t%s\nLittle:\t\t%s\n", big, little);
	printf("----------------------------------------\n");
	if (ft_strnstr(big, little, len))
		printf("Found:\t\t%s\n", ft_strnstr(big, little, len));
	else
		printf("Sorry, not found\n");
	return (0);
}
*/

// DESCRIPTION
/* The strnstr() function locates the first occurrence of the null-termi‐
 * nated string little in the string big, where not more than len charac‐
 * ters are searched.  Characters that appear after a ‘\0’ character are
 * not searched.  Since the strnstr() function is a FreeBSD specific API,
 * it should only be used when portability is not a concern.
 *
 * If little is an empty string, big is returned; if little occurs nowhere
 * in big, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of little is returned.
 */
