/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:31:08 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/01 09:16:26 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	char	c;

	c = '.';
	if (ft_isascii(c))
		printf("\n\n\nThe character is ASCII!\n\n\n");
	else
		printf("\n\n\nThe character is not ASCII!\n\n\n");
	return (0);
}
*/

// DESCRIPTION
/*
 * The isascii() function tests for an ASCII character, which is any character
 * between 0 and octal 0177 inclusive.
 */
