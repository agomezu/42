/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:29:25 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/16 08:39:10 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>
#include "libft.h"

char
	*ft_strrchr(const char *s, int c);

/*** main function test
 *
int	main(void)
{
	char	str[] = "hello my name is ale";
	char	c = 'a';

	printf("%c\n", *ft_strrchr(str, c));
	return (0);
} 
*/

char
	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((*s != '\0'))
		s++;
	while ((*s != c))
		s--;
	if ((*s == c))
		return ((char*)(s));
	return ((char*)NULL);
}
