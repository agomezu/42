/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:26:33 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 20:29:16 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isdigit(int c);

int	
	ft_isdigit(int c)
{
	if (( c >= '0' && c <= '9'))
		return true;
	else
		return false;
}
