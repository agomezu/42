/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:59:32 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/20 21:07:38 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew((f)(lst->content));
	if (!new)
		return (0);
	list = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((f)(lst->content));
		if (!new->next)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (list);
}

// TEST

// DESCRIPTION
/* Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 */
