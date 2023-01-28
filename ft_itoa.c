/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:29:04 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/28 13:30:29 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_itoa(int n);

static long int
	ft_len(int n);

static char
	*ft_asign(char *x, unsigned int nbr, long int len);

/* 
static int
	ft_abs(int nbr);

static int
	ft_abs(int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}
*/

static char
	*ft_asign(char *str, unsigned int nbr, long int len)
{
	while (nbr > 0)
	{

		*(str + len--) = ('0' + (nbr % 10));
		//printf("\nThe asigned number is %d", (nbr % 10));
		nbr = (nbr / 10);
	}
	return (str);
}

static long int
	ft_len(int nbr)
{
	int	len;

	len = 0;
	// !!
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char
	*ft_itoa(int n)
{
	char	*x;
	int	sign;
	long int	len;
	unsigned int	number;

	sign = 1;
	len = ft_len(n);	
	// printf("The length of the number is: %ld", len);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (!x)
		return (0);	
	*(x + len--) = 0;
	if (n == 0)
		*(x + 0) = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		*(x + 0) = '-';
	}
	else
		number = n;
	x = ft_asign(x, number, len);
	// printf("And the string is: %s", x);
	return (x);
}
