/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:48:13 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/06 22:44:30 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*destination;
	const char	*source;

	i = 0;
	destination = (char *)dst;
	source = (const char *)src;
	if (dstsize)
	{
		ft_memcpy(destination, source, dstsize);
		destination[dstsize] = 0;
	}
	return (ft_strlen(source));
}

// TEST
/* int	main(void)
{
	char	src[] = "this is the string to copy!";
	char	dst[] = "destination variable";
	int	n;

	printf("\n\n-> SOURCE: %s\n-> DESTINATION: %s\n", src, dst);
	n = (int)ft_strlen(src);
	ft_strlcpy(dst, src, n);
	printf("\nTotal length of source: %d\n", n);
	// including NUL in dstsize
	printf("\nAfter using ft_strlcpy with %d characters:\n-> %s\n\n\n", n, dst);
	return (0);
}
*/

// DESCRIPTION
/* The strlcpy() and strlcat() functions copy and concatenate strings with the
 * same input parameters and output result as snprintf(3).  They are designed to
 * be safer, more consistent, and less error prone replacements for the easily
 * misused functions strncpy(3) and strncat(3).
 *
 * strlcpy() and strlcat() take the full size of the destination buffer and
 * guarantee NUL-termination if there is room.  Note that room for the NUL should
 * be included in dstsize.  Also note that strlcpy() and strlcat() only operate
 * on true ''C'' strings. This means that for strlcpy() src must be NUL-
 * terminated and for strlcat() both src and dst() must be NUL-terminated.
 *
 * strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-
 * terminating the result if dstsize is not 0.
 *
 * If the src and dst strings overlap, the behavior is undefined.
 *
 * Like snprintf(3), the strlcpy() and strlcat() functions return the total
 * length of the string they tried to create.  For strlcpy() that means the
 * length of src.
 * 
 * If the return value is >= dstsize, the output string has been truncated.  It
 * is the caller's responsibility to handle this.
 */
