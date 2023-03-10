/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:59:42 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:52:49 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char
	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	if (!s1)
		return (NULL);
	*ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (!str)
		return (0);
	while (s[i++])
		ptr[i] = s[i];
	s[i] = 0;
	return (ptr);
}

// TEST
int	main(void)

// TEST
int	main(void)
{
	return 0;
}{
	return 0;
}
// DESCRIPTION
/* The strdup() function returns a pointer to a new string which is a du‐
 * plicate of the string s.  Memory for the new string is  obtained  with
 * malloc(3), and can be freed with free(3).
 *
 * On  success, the strdup() function returns a pointer to the duplicated
 * string.  It returns NULL if insufficient memory  was  available,  with
 * errno set to indicate the cause of the error.
 */
