/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:06:56 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:38:23 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// TEST
/* int	main(void)
{
	char	c = 'a';

	printf("\nFrom %c -> ft_toupper() -> %c\n",
		c, ft_toupper(c));
	return (0);
}
*/

// DESCRIPTION
/* These functions convert  lowercase  letters  to  uppercase,  and  vice
 * versa.
 *
 * If  c  is  a lowercase letter, toupper() returns its uppercase equiva‐
 * lent, if an uppercase representation exists  in  the  current  locale.
 * Otherwise,  it  returns c.  The toupper_l() function performs the same
 * task, but uses the locale referred to by the locale handle locale.
 *
 * If  c is neither an unsigned char value nor EOF, the behavior of these
 * functions is undefined.
 *
 * The value returned is that of the converted letter, or c if  the  con‐
 * version was not possible.
 */
