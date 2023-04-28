/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:10:23 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/19 15:52:06 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int
	ft_putnbr_base(uintptr_t nbr, char *base, int *count)
{
	uintptr_t			base_length;

	base_length = ft_strlen(base);
	if (nbr >= (uintptr_t)base_length)
		ft_putnbr_base(nbr / base_length, base, count);
	ft_putchar(base[nbr % base_length]);
	(*count)++;
	return (0);
}

int
	ft_printf_d(int nbr)
{
	int				count;
	unsigned int	unbr;

	count = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = abs(nbr);
		count++;
	}
	else
		unbr = abs(nbr);
	ft_putnbr_base(unbr, "0123456789", &count);
	return (count);
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
	ft_putnbr_base((uintptr_t)ptr, base, &count);
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
