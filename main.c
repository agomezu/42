/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:58:55 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/25 22:40:21 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	str[] = "hello, hello, hello... how are you, machine?";
	char	c = 'h';
	size_t	i = 0;

	while (*(ft_split(str, c)+i++))
		printf("\n%s", *ft_split(str, c) + i);
	return (0);
}
