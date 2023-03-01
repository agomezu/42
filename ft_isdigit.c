/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:26:33 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/01 09:12:20 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	
	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// TEST 
/*
int	main(void)
{
	char	c;

	c = '1';
	if (ft_isdigit(c))
		printf("\n\n\nIs digit!\n\n\n");
	else
		printf("\n\n\nIs not digit!\n\n\n");
	return(0);
}
*/

// DESCRIPTION
/*
 * The isdigit() function tests for a decimal digit character.  Regardless of
 * locale, this includes the following characters only:
 *
 * ``0''``1''``2''``3''``4''
 * ``5''``6''``7''``8''``9''
 *
 * The isdigit() and isnumber() functions return zero if the character tests
 * false and return non-zero if the character tests true.
 */
