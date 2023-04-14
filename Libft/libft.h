/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:07:53 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/23 22:53:54 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>

// *************************************
// BONUS PART. TYPEDEF STRUCT PROTOTYPE*
// *************************************

/* The members of the t_list struct are:
 * content: The data contained in the node
 * void * allows to store any kind of data.
 * next: The address of the next node,
 * or NULL if the next node is the last one. */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

// BONUS: FUNCTIONS

/* Functions of the bonus part that work
 * with the typedef struct s_list structure. */

t_list		*ft_lstnew(void *content);

void		ft_lstadd_front(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst, void (*del)(void*));

void		ft_lstclear(t_list **lst, void (*del)(void*));

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// **************************
// PART ONE: LIBC FUNCTIONS *
// **************************

/* The libft library is a collection of commonly used functions 
 *  in the C programming language, designed to be portable
 *  and compatible with various platforms. It contains functions
 *  that are not part of the standard C library, such as string
 *  manipulation, memory allocation, and linked list operations.
 *
 *  The library is organized into several modules, each containing
 *  a set of related functions. These modules include memory,
 *  strings, characters, numbers, lists, and other utility fts.
 *
 *  The library is intended to provide a convenient set of tools
 *  for C programmers, allowing them to write code more efficiently
 *  and with fewer bugs. It is also used as a learning tool
 *  for people new to the C programming language, as it provides
 *  a good example of how to write modular and reusable code.
 *
 *  The libft library is often used in conjunction with other C
 *  libraries and frameworks, and is commonly included in larger
 *  C projects */

// NO POINTER FUNCTIONS OF PART ONE

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

size_t		ft_strlen(const char *s);

void		ft_bzero(void *s, size_t n);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

int			ft_toupper(int c);

int			ft_tolower(int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

int			ft_atoi(const char *str);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

/*********************
/ POINTER FUNCTIONS  *
// ------------------*
// PART ONE AND TWO  *
/ *******************/

/* A function declared with a pointer is a function that returns
 * a memory address instead of a specific value.
 *
 * This memory address can then be used to access the data
 * that the function has generated or modified.
 *
 * This can be useful in situations where the data returned 
 * by the function is large or complex, or where the function
 * needs to modify data in place rather than returning a copy.
 *
 * Using pointers can also improve performance by reducing
 * he amount of data that needs to be copied or passed around. */

void		*ft_memset(void *b, int c, size_t len);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *s, int c);

void		*ft_memchr(const void *s, int c, size_t n);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s1, char const *set);

char		**ft_split(char const *s, char c);

char		*ft_itoa(int n);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
