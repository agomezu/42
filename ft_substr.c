/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:05:38 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/20 08:37:43 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len);

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;	
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i++ < start)
		s++;
	ft_strlcpy(str, s, len);
	return (str);
}	
