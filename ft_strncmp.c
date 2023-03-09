/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:35:06 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:39:00 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	const char	*p1;
	const char	*p2;

	i = 0;
	p1 = (const char*)s1;
	p2 = (const char*)s2;
	while (p1[i] && p2[i] && i < n)
	{
		if (p1[i] != p2[i])
			return((int)(p1[i] - p2[i]));
		++i;
	}
	if (i == n)
		return (0);
	return ((int)(p1[i]- p2[i]));
}

// TEST
/* int	main(void)
{
	const char	str1[] = "this is a f**king string!";
	const char	str2[] = "this is also!";

	printf("\nComparision with ft_strncmp() between this two strings:");
	printf("\n-> %s\n-> %s\n", str1, str2);
	int	len;
	if (ft_strlen(str1) > ft_strlen(str2))
		len = ft_strlen(str1);
	else
		len = ft_strlen(str2);
	printf("\nResult:\t%d\n\n", ft_strncmp(str1, str2, len));
	return (0);
}
*/

// DESCRIPTION
/* The  strcmp() function compares the two strings s1 and s2.  The locale
 * is not taken into account (for a  locale-aware  comparison,  see  str‐
 * coll(3)).   It returns an integer less than, equal to, or greater than
 * zero if s1 is found, respectively, to be less than, to  match,  or  be
 * greater than s2.
 *
 * The  strncmp()  function is similar, except it compares only the first
 * (at most) n bytes of s1 and s2.
 *
 * The strcmp() and strncmp() functions  return  an  integer  less  than,
 * equal to, or greater than zero if s1 (or the first n bytes thereof) is
 * found, respectively, to be less than, to match, or be greater than s2.
 */
