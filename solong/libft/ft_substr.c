/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:05:38 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/21 12:15:12 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// TEST
/* int	main()
{
	char	str[] = "copy this, please";
	char	*ptr;

	printf("String to copy with ft_substr():\n%s\n", str);
	printf("Executing the function...\n\n\n");
	ptr = (char *)ft_substr(str, 2, 5);
	printf("Result:\n%s\n", ptr);
	return (0);
}
*/

// DESCRIPTION
/* Allocates (with malloc(3)) and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 */
