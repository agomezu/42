/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:07:40 by agomez-u          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/19 15:39:27 by agomez-u         ###   ########.fr       */
=======
/*   Updated: 2023/04/22 11:11:44 by agomez-u         ###   ########.fr       */
>>>>>>> 027ccdb72aea9b65f576b457c7bc5686eaf30293
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	ft_putchar(char c)
{
	if (!c)
		return (-1);
	return (write(1, &c, 1));
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
		else
			++i;
	}
	va_end(args);
	return (count);
}
