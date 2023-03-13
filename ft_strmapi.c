/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:37:51 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:41:58 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (!s || !f)
		return (0);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (0);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		++i;
	}
	newstr[i] = 0;
	return (newstr);
}

// TEST
/*static char
	capitalize(unsigned int i, char s)
{
	// in this case index is not used
	return (ft_toupper(s));
}


int	main(void)
{
	char	str[] = "applies the function to each character";
	char	*ptr;

	printf("Using ft_strmapi() with the following string:\n\'%s\'\n",
		str);
	ptr = (char *)ft_strmapi(str, capitalize);
	if (!ptr)
	{
		printf("\nError\n");
		return (0);
	}
	printf("\n\n-----------------------------------------\n\n");
	while (*ptr)
	{
		printf("%c", *ptr);
		ptr++;
	}
	printf("\n");
	return (0);
}
*/

// DESCRIPTION
/* Applies the function ’f’ to each character of the
 * string ’s’, and passing its index as first argument
 * to create a new string (with malloc(3)) resulting
 * from successive applications of ’f’.
 */
