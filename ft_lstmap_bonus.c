/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:59:32 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/21 06:57:11 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*actual;
	t_list	*new;

	actual = (t_list *)malloc(sizeof(t_list *) * ft_lstsize(lst));
	new = (t_list *)malloc(sizeof(t_list *) * ft_lstsize(lst));
	if (!actual || !new)
		return (0);
	new = ft_lstnew(actual->content);
	actual = actual->next;
	new = new->next;
	while (actual && new)
	{
		new->content = (f)(actual->content);
		(del)(actual->content);
		actual = actual->next;
		new = new->next;
	}	
	free(actual);
	return (new);
}
