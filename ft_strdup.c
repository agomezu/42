/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:59:42 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 22:53:58 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*strdup(const char *s1);

char
	*strdup(const char *s1)
{
	size_t	i;
	char	*str;

	if (!s1)
		return (0);
	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (!str)
		return (0);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++
	}
	*(str + i) = 0;
	return (str);
}
