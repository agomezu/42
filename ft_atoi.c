/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:27 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 18:52:31 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_atoi(const char *str);
int
	ft_atoi(const char *str)
{
	size_t		i;
	unsigned int	sgn;
	int		res;

	if (!str || str == NULL)
		return (0);
	i = 0;
	sgn = 1;
	res = 0;
	if (*(str + 0) == '0' && (*(str + 1) == ' ' || *(str + 1) == 0))
		return ((int)0);
	while (*(str + i) == '0' || *(str + i) == ' ' || *(str + i) == '\n' \
		|| *(str + i) == '\t' || *(str + i) == '\r' || *(str + i) == '\v' \
		|| *(str + i) == '\f')
		i++;
	if (*(str + i) == '+')
		++i;
	else if (*(str + i) == '-')
	{
		sgn = -1;
		++i;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = (res * 10) + (*(str + i) - '0');
		++i;
	}
	return ((int)(res * sgn));
}
