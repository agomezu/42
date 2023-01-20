/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:08:57 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/20 18:29:42 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin(char const *s1, char const *s2);

char
	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	else
	{
		len = ft_strlen(s1)-1;
		len += ft_strlen(s2)-1;
	}
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (0);
	while (*(s1))
		*(char*)(str++) = *(char*)(s1++);
	while (*(s2))
		*(char*)(str++) = *(char*)(s2++);
	*(str) = '\0';
       return (str);
}       
