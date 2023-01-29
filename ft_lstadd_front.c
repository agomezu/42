/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:19:00 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/29 18:17:27 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_front(t_list **lst, t_list *new);

void
	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int
	main(void)
{
	int	n = 123;
	int	m = 321;
	t_list *new_list;

	new_list = ft_lstnew(&n);
	printf("Content of the first list: %d\n", *(int*)new_list->content);
	printf("Next: %p\n", new_list->next);

	t_list *new_new_list;
	new_new_list = ft_lstnew(&m);
	printf("Content of the second list: %d\n", *(int*)new_new_list->content);
	printf("Next: %p\n", new_new_list->next);

	printf("After ft_lstnew on second list the direction of the pointer *next is: %p\n", new_list->next);

	printf("\nNow, lets switch the nodes...\n");

	ft_lstadd_front(&new_list, new_new_list);
	printf("Content of the first list: %d\n", *(int*)new_list->content);
	printf("Next: %p\n", new_list->next);

}
*/
