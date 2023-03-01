/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:32:01 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/01 09:31:38 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isprint(int c)
{
	return (c >= 040 && c <= 176);
}

// TEST
/*
int	main(void)
{
	char	c;

	c = '}';
	if (ft_isprint(c))
		printf("\n\n\nThe character is printeable!\n\n\n");
	else	
		printf("\n\n\nThe character is not printeable!\n\n\n");
	return (0);
}
*/

// DESCRIPTION
/*
 * The isprint() function tests for any printing character, including space
 * (‘ ’).  The value of the argument must be representable as an unsigned char or
 * the value of EOF.
 *
 * The isprint() function returns zero if the character tests false and returns
 * non-zero if the character tests true.
 */
