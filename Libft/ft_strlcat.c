/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:04:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/22 20:43:42 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (*(src) && dst_len + 1 < dstsize)
	{
		dst[dst_len] = *(src);
		dst_len++;
		src++;
	}
	dst[dst_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

// TEST
/*int	main(void)
{
	char	src[] = "this is the source to copy";
	char	dst[] = "destination var... ";

	printf("\n\nWe start with two srings:\n"
		"-----------------------------------------\n"
		"-> %s\n"
		"-> %s\n", src, dst);
	size_t	n = 33;
	printf("\n\nWe are using ft_strlcat() with a destination\n"
		"variable of %ld characters (one for NUL).", n);
	printf("\n\nThe return value of function is: %ld",
		ft_strlcat(dst, src, n));
	printf("\n\nAnd the result of destination variable is:\n-> %s\n",
		dst);
	printf("\n\n");
	return (0);
}
*/

// DESCRIPTION
/* The strlcat() function appends the NUL-terminated string src to the end
 * of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
 * nating the result.
 *
 * The strlcpy() and strlcat() functions return the total length of the
 * string they tried to create.  For strlcpy() that means the length of
 * src. For strlcat() that means the initial length of dst plus the length
 * of src.  While this may seem somewhat confusing, it was done to make
 * truncation detection simple.
 */
