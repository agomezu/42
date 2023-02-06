/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:27 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/06 19:10:57 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_atoi(const char *str);

int
	ft_atoi(const char *str)
{
	size_t	i;
	unsigned int	sgn;
	long long	res;

	if (!str)
		return (0);
	i = 0;
	while (*(str + i) == ' ' && *(str + i) >= 9 && *(str + i) <= 13)
		i++;
	sgn = 1;
	res = 0;
	if (*(str) == '+')
		i++;
	else if (*(str) == '-')
	{
		sgn = -1;
		++i;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = (res * 10) + (*(str + i) - '0');
		i++;
	}
	return ((int)(res * sgn));
}
