/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:06:56 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 08:09:49 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_toupper(int c);

int
	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
