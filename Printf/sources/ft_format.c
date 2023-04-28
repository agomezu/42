/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:08:18 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/22 11:05:32 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int
	check_ret_and_increment(int ret, int *count)
{
	if (ret == -1 || *count == -1)
		return (-1);
	*count += ret;
	return (1);
}

int
	process_format(char format_char, va_list *args)
{
	int	ret;

	if (format_char == 'c')
		ret = ft_printf_c(va_arg(*args, int));
	else if (format_char == 's')
		ret = ft_printf_s(va_arg(*args, char *));
	else if (format_char == 'p')
		ret = ft_printf_p(va_arg(*args, void *));
	else if (format_char == 'd' || format_char == 'i')
		ret = ft_printf_d(va_arg(*args, int));
	else if (format_char == 'u')
		ret = ft_printf_u(va_arg(*args, int));
	else if (format_char == 'x' || format_char == 'X')
		ret = ft_printf_x(va_arg(*args, unsigned int), &format_char);
	else if (format_char == '%')
		ret = ft_printf_percent();
	else
		ret = ft_putchar(format_char);
	return (ret);
}
