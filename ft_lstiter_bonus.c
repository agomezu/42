/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:01:41 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 08:10:03 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstiter(t_list *lst, void (*f)(void *));

void
	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst)
	{
		ptr = lst;
		while (1)
		{
			(*f)(ptr->content);
			ptr = ptr->next;
			if (ptr == NULL)
				return ;
		}
	}
}
