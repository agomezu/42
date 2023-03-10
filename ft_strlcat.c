/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:04:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:38:11 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*destination;
	unsigned const char	*source;
	size_t	d_length;
	size_t	s_length;

	d_length = ft_strlen(dst);
	s_length = ft_strlen(src);
	if (dstsize <= d_length)
		return (dstsize + s_length);
	destination = (unsigned char *)dst;
	source = (unsigned const char *)src;
	ft_memmove(destination + d_length, source + 0, dstsize - 1);
	/* while (source[i] && (d_length + 1) < dstsize)
	{
		destination[d_length] = source[i];
		d_length += 1;
		++i;
	}*/
	if (!destination[dstsize])
		destination[dstsize] = '\0';
	return (d_length + s_length);
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
