/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:31:08 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 20:31:32 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isascii(int c);

int
	ft_isascii(int c)
{
	if (( c >= 0 && c <= 127))
		return true;
	else
		return false;
}

