/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:15:12 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 08:26:58 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c);

int	main(void)
{
	const char	str[] = "i'm coding too late";
	char	e;;

	e = 'a';
	printf("%c\n", *ft_strchr(str, e));
	return (0);
}

char
	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	
	while ((*s != '\0') && (*s != c))
		s++;
	if (*s == c)
		return ((char*)s);
	return ((char*)NULL);	
}