/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:10:30 by agomez-u          #+#    #+#             */
/*   Updated: 2023/04/14 12:11:59 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // To manage function write()
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h> // To manage variable arguments (va_start, va_arg, etc.)
# include <stddef.h> // To type size_t
# include <stdint.h>  // For holding object pointers (UINTPTR_MAX)

// Numbers

int	ft_putnbr_base(uintptr_t nbr, char *base, int *count);

int	ft_putnbr_unsigned(unsigned int nbr);

// String manipualtion

int	ft_putchar(char c);

int	ft_strlen(const char *s);

int	ft_putstr(const char *s);

// Conversion function prototypes

int	ft_printf_c(char c);

int	ft_printf_s(char *s);

int	ft_printf_p(void *ptr);

int	ft_printf_d(int nbr);

int	ft_printf_i(int nbr);

int	ft_printf_u(unsigned int nbr);

int	ft_printf_x(unsigned int nbr, const char *format);

int	ft_printf_percent(void);

// Principal function prototype

int	check_ret_and_increment(int ret, int *count);

int	process_format(char format_char, va_list *args);

int	ft_printf(const char *format, ...);

#endif
