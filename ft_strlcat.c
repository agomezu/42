/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:04:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/06 22:58:05 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char	destination;
	unsigned const char	source;
	size_t	d_len;
	size_t	s_len;

	destination = (unsigned char *)dst;
	source = (unsigned const char *)src;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (*(src) && dst_len + 1 < dstsize)
	{
		*(dst + dst_len) = *(src);
		dst_len++;
		src++;
	}
	*(dst + dst_len) = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

// TEST

// DESCRIPTION
/* strlcat() appends string src to the end of dst.  It will append at most
 * dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
 * dstsize is 0 or the original dst string was longer than dstsize (in practice
 * this should not happen as it means that either dstsize is incorrect or that
 * dst is not a proper string).
 *
 * If the src and dst strings overlap, the behavior is undefined.
 *
 * Like snprintf(3), the strlcpy() and strlcat() functions return the total
 * length of the string they tried to create.
 * For strlcat() that means the initial length of dst plus the
 * length of src.
 *
 * If the return value is >= dstsize, the output string has been truncated.
 * is the caller's responsibility to handle this.
 */
