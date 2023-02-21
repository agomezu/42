/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:18:30 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/18 10:51:34 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstnew(void *content);

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

/*
int	main(void)
{
	int	x = 111;
	t_list	*new_list;
	new_list = ft_lstnew(&x);
	printf("Content: %d\n", *(int*)new_list->content);
	printf("Next: %p\n", new_list->next);
	return (0);
}
*/
