/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:19:26 by agomez-u          #+#    #+#             */
/*   Updated: 2023/05/13 12:19:27 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024 
# endif

char	*get_next_line(int fd);

// Prototypes for auxiliar functions needed

char	*ft_strchr(const char *s, int c);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strmerge(char const *s1, char const *s2);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
