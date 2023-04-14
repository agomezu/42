/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:18:54 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/14 12:17:57 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int
	ft_printf_c(char c)
{
	return (ft_putchar(c));
}

int
	ft_printf_s(char *s)
{
	if (s == NULL)
		s = "(null)";
	return ((int)ft_putstr(s));
}

int
	ft_printf_percent(void)
{
	return (ft_putchar('%'));
}
