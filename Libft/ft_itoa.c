/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:29:04 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/22 20:25:10 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int
	ft_number_len(long int nbr)
{
	long int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{	
		nbr = nbr / 10;
		++len;
	}
	return (len);
}

static char
	*ft_asign(char *str, long int nbr, long int len)
{
	while (nbr > 0)
	{
		str[len] = ((nbr % 10) + '0');
		nbr /= 10;
		--len;
	}
	return (str);
}

char
	*ft_itoa(int n)
{
	long int		len;
	char			*newstr;
	long int		nbr;

	nbr = n;
	len = ft_number_len(nbr);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	newstr[len--] = 0;
	if (nbr == 0)
		newstr[0] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		newstr[0] = '-';
	}
	ft_asign(newstr, nbr, len);
	return (newstr);
}

// TEST
/* int	main(void)
{
	int	n = -1337;
	char	*str;

	printf("Turning into string:\t%d\n", n);
	str = ft_itoa(n);
	printf("\nPrint new string:\t%s\n", str);
	return (0);
}
*/

// DESCRIPTION
/* Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * 
 * This is a function that takes an integer and returns
 * a new string representation of it.
 *
 * It allocates memory for the new string using malloc
 * and then converts the integer to a string by iterating
 * over each digit and appending it to the new string.
 *
 * If the integer is negative, it adds a minus sign
 * to the beginning of the string. Finally, it returns
 * the new string.
 */
