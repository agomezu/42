/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:34:40 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/06 14:43:12 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// TEST
/*
int	main(void)
{
	char	a[12] = "hello world!";

	printf("\n\n\nThe length of string: \'%s\' is %ld\n\n\n", 
						a, ft_strlen(a));
	printf("\n\n\nThe length of string: \'%s\' is %ld\n\n\n", 
						a, strlen(a));
	
	return (0);
}
*/

// DESCRIPTION
/*
 * The strlen() function computes the length of the string s.  The strnlen()
 * function attempts to compute the length of s, but never scans beyond the first
 * maxlen bytes of s.
 *
 * The strlen() function returns the number of characters that precede the
 * terminating NUL character.
 */
