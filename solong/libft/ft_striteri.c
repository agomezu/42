/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:27:57 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:42:14 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		++i;
	}
}

// TEST
/* void
	lowercase(unsigned int i, char *s)
{
	*s = ft_tolower(*s);
}

int	main(void)
{
	char	str[] = "WHAT DOES THIS DO?";

	printf("Using \'%s\' into ft_striter(s, (f))", str);
	ft_striteri(str, lowercase);
	printf("\nResult:\n%s\n", str);
	return (0);
}
*/

// DESCRIPTION
/* Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary.
 */
