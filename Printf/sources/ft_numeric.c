/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:10:23 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/22 10:57:08 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int
	ft_putnbr_base(uintptr_t nbr, char *base, int *count)
{
	uintptr_t			base_length;

	base_length = ft_strlen(base);
	if (!base_length)
		return (-1);
	if (nbr >= (uintptr_t)base_length)
		ft_putnbr_base(nbr / base_length, base, count);
	if ((ft_putchar(base[nbr % base_length])) == -1)
		return (0);
	else
	{
		(*count)++;
		return (1);
	}
}

int
	ft_printf_d(int nbr)
{
	int				count;
	unsigned int	unbr;

	count = 0;
	if (nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		unbr = abs(nbr);
		count++;
	}
	else if (nbr == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		else
			return (1);
	}
	else
		unbr = abs(nbr);
	if (ft_putnbr_base(unbr, "0123456789", &count))
		return (count);
	else
		return (-1);
}

int
	ft_printf_u(unsigned int nbr)
{
	int	count;

	count = 0;
	ft_putnbr_base(nbr, "0123456789", &count);
	return (count);
}

int
	ft_printf_x(unsigned int nbr, const char *format)
{
	int	count;

	count = 0;
	if (*format == 'x')
		ft_putnbr_base(nbr, "0123456789abcdef", &count);
	else if (*format == 'X')
		ft_putnbr_base(nbr, "0123456789ABCDEF", &count);
	return (count);
}

int
	ft_printf_p(void *ptr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (ptr == NULL)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	if (count == -1)
		return (-1);
	ft_putnbr_base((uintmax_t)ptr, base, &count);
	if (count == -1)
		return (-1);
	return (count);
}

/* int
	ft_putnbr_unsigned(unsigned int nbr)
{
	if (nbr >= 10)
		ft_putnbr_unsigned(nbr / 10);
	ft_putchar((nbr % 10) + '0');
	return (0);
} */
