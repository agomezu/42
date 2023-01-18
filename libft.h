/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:07:53 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/18 20:59:56 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

size_t			ft_strlen(const char *s);

void			ft_bzero(void *s, size_t n);

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

// functions with pointers

void		*ft_memset(void *b, int c, size_t len);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);
#endif
