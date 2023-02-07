/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:59:32 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/07 18:59:34 by agomez-u         ###   ########.fr       */
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

	if (!lst || !f)
		return (0);
	actual = (t_list *)malloc(sizeof(t_list *));
	new = (t_list *)malloc(sizeof(t_list *));
	if (!actual || !new)
		return (0);
	actual = lst;
	ft_lstiter(actual, (f)(actual->content));
	new = actual;
	ft_lstclear(&actual, (f)(actual->content));
	free(actual);
	return (new);
}
