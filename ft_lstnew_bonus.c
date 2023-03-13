/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:18:30 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:43:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstnew(void *content)
{
	t_list	*x;

	x = (t_list *)malloc(sizeof(*x));
	if (!x)
		return (0);
	x->content = content;
	x->next = NULL;
	return (x);
}

// DESCRIPTION
/* Allocates (with malloc(3)) and returns a new node.
/* The member variable ’content’ is initialized with
/* the value of the parameter ’content’. The variable
/* ’next’ is initialized to NULL.
/*