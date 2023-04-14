/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:29:51 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/01 09:11:34 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// TEST
/*
int	main(void)
{
	char	c;

	c = 'a';
	if (ft_isalnum(c))
		printf("\n\n\nThe character is alphanumeric!\n\n\n");
	else
		printf("\n\n\nThe character is not alphanumeric!\n\n\n");
	return (0);
}
*/

// DESCRIPTION
/*
 * The isalnum() function tests for any character for which isalpha(3) or
 * isdigit(3) is true.  The value of the argument must be representable as an
 * unsigned char or the value of EOF.
 *
 * The isalnum() function returns zero if the character tests false and returns
 * non-zero if the character tests true.
 */
