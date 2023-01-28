/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:02:00 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/28 17:06:48 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putstr_fd(char *s, int fd);

void
	ft_putstr_fd(char *s, int fd)
{
	while (*(s))
		write(fd, s++, 1);
}
