/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:04:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/12 20:22:21 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize);

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
		*(dst + dst_len) = *(src);
		dst_len++;
		src++;
	}
	*(dst + dst_len) = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
/*
int	main(void)
{
	char	a[] = "hello world";
	char	b[] = "12345";
	int	n = ft_strlcat(a, b, 17);

	printf("%d\n%s\n", n, a);
	return (1);
} */
