/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:29:04 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/27 21:36:24 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_itoa(int n);

static int
	ft_num_len(int n);

static void
	ft_asign_num(char *s, int n, int len, int sign);

static void
	ft_asign_num(char *s, int n, int len, int sign)
{
	int	tmp_n;

	tmp_n = 0;
	n *= 1;
	*(s + len) = 0;
	--len;
	while (n > 0)
	{
		tmp_n = n % 10;
		*(s + len) = (tmp_n + '0');
		--len;	
		if (len == 0 && sign == -1)
			*(s + len) = '-';
	}

}

static int
	ft_num_len(int n)
{
	int	len;

	if (n >= 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

char
	*ft_itoa(int n)
{
	char	*num;
	int	sign;
	int	len;

	if (!n)
		return (0);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_num_len(n);
	if (sign == -1)
		num = (char*)malloc(sizeof(*num) * (len += 2));
	else if (sign == 1)
		num = (char*)malloc(sizeof(*num) * (len += 1));
	if (!num)
		return (0);
	ft_asign_num(num, n, len, sign);
	return (num);
}
