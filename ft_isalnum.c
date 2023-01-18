/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:29:51 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 21:18:30 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_isalnum(int c);

int
	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return true;
	else
		return false;
}
