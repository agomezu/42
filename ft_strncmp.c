/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:42:13 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 19:05:43 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

/*
int	main(void)
{
	char	str1[] = "hbllo world";
	char	str2[] = "hallo world";

	printf("%d\n", ft_strncmp(str1, str2, 11));
	return (0);
} 
*/

int
	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	else
	{
		i = 0;
		while ((*(s1 + i) == *(s2 + i)) && (i < n))
			i++;
		if (*(s1 + i) == 0 && *(s2 + i) == 0)
			return (0);
		else
			return (*(s1 + i) - *(s2 + i));
	}
}
