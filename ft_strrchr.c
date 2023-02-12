/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:29:25 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/12 21:25:03 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strrchr(const char *s, int c);

char
	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	int	i;

	ret = NULL;
	i = 0;
	while (*(s))
	{
		if (*(s) == (char)c)
			ret = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	if (ret)
		return ((char*)ret);
	if (!ret)	
		return ((char*)NULL);
}
