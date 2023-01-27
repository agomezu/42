/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:29:04 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/27 23:32:17 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_itoa(int n);

static int
	ft_num_len(int n);

static void
	ft_asign_num(char **s, int n, int len, int sign);

static void
	ft_asign_num(char **s, int n, int len, int sign)
{
	int	n_tmp;

	n_tmp = 0;
	*(*s + len) = '\n';
	--len;
	while (n > 0)
	{
		if (n % 10)
		{
			n_tmp = n % 10;
			*(*s + len) = (n_tmp + '0');
		}
		else if ((n % 10 == 0) && (n > 0 && n < 10))
			*(*s + len) = (n + '0');
		--len;
	}
	if (!sign && len == 0)
		*(*s + len) = '-';
}

static int
	ft_num_len(int num)
{
	int	len;

	len = 0;	
	while (num != 0)
	{
		++len;
		num = num / 10;
	}
	return (len);
}

char
	*ft_itoa(int n)
{
	char	*num;
	int	sign;
	int	len;

	sign = 1;
	if (!n)
		return (0);
	if (n < 0)
	{
		sign = 0;
		n = -1;
	}
	printf("\n%d", n);
	len = ft_num_len(n);
	// printf("\n%d", len);
	if (sign)
		num = (char*)malloc(sizeof(char) * (len += 1));	
	else if (!sign)
		num = (char*)malloc(sizeof(char) * (len += 2));
	//printf("\n%d", len);
	if (!num)
		return (0);	
	ft_asign_num(&num, n, len, sign);
	return (num);
}
