/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:08:57 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/23 14:51:51 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// TEST
/* int	main(void)
{
	char	p_s1[] = "string one";
	char	p_s2[] = "string two";

	printf("\nUsing ft_strjoin()\n");
	printf("We have this two strings:\n");
	printf("-> %s\n-> %s\n\n", p_s1, p_s2);
	printf("Using function...\nResult:\t\t%s", 
		(char *)ft_strjoin(p_s1, p_s2));
	printf("\n\n");
	return (0);
}
*/

// DESCRIPTION
/* Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of ’s1’ and ’s2’.
 */
