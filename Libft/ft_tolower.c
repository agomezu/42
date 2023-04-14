/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:06:42 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:38:32 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// TEST
/* int	main(void)
{
	char	c = 'A';

	printf("\nFrom %c -> ft_tolower() -> %c\n",
		c, ft_tolower(c));
	return (0);
}
*/

// DESCRIPTION
/* If c is an uppercase letter, tolower() returns its  lowercase  equiva‐
 * lent,  if  a  lowercase  representation  exists in the current locale.
 * Otherwise, it returns c.  The tolower_l() function performs  the  same
 * task, but uses the locale referred to by the locale handle locale.
 *
 * If  c is neither an unsigned char value nor EOF, the behavior of these
 * functions is undefined.
 *
 * The value returned is that of the converted letter, or c if  the  con‐
 * version was not possible.
 */
