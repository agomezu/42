/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:40 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/14 12:09:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int
	ft_putchar(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret == -1)
		return (-1);
	else
		return (1);
}

int
	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int
	ft_putstr(const char *s)
{
	int	ret;

	if (!s)
		return (ft_putstr("(null)"));
	ret = write(1, s, ft_strlen(s));
	if (ret == -1)
		return (-1);
	else
		return (ret);
}

int
	ft_printf(char const *format, ...)
{
	size_t	i;
	int		ret;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			ret = process_format(format[++i], &args);
		else if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		else
			ret = ft_putchar(format[i]);
		if (check_ret_and_increment(ret, &count) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}
