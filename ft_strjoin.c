/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:08:57 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 07:44:32 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strjoin(char const *s1, char const *s2);

char
	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (*(s1 + j))
		*(char *)(str + i++) = *(char *)(s1 + j++);
	j = 0;
	while (*(s2 + j))
		*(char *)(str + i++) = *(char *)(s2 + j++);
	*(str + i) = '\0';
	return (str);
}
