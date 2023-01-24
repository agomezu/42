/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slipt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:05:28 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/24 19:56:45 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	**ft_split(char const *s, char c);

char
	**ft_split(char const *s, char c)
{
	size_t	i;
	int	count;
	char	**str;
	i = 0;
	count = 0;	
	while (*(s + i))
		if (*(s + i) == c)
		       count++;
	str = (char**)malloc(sizeof(*s) * count + 1);		
	
}
