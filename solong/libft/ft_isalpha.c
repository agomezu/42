/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:25:47 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/01 09:12:03 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// TEST 
/*
int	main(void)
{
	char	c;

	c = 'A';
	if (ft_isalpha(c))
		printf("\n\n\nThe character is alpha!\n\n\n");
	else
		printf("\n\n\nThe character is not alpha!\n\n\n");
	return (0);
}
*/

// DESCRIPTION
/*
 * The isalpha() function tests for any character for which isupper(3) or
 * islower(3) is true.  The value of the argument must be representable as an
 * unsigned char or the value of EOF.
 *
 * The isalpha() function returns zero if the character tests false and returns
 * non-zero if the character tests true.
 */
