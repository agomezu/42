/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:31:28 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/17 13:28:36 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*(lst));
		tmp->next = new;
	}
}

// TEST
/* int	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*tmp;

	// assigning values to the content of lists
	lst1 = ft_lstnew("1");
	lst2 = ft_lstnew("2");
	lst3 = ft_lstnew("3");
	// linking only list 1 and 2
	lst1->next = lst2;
	// using the function ft_lstadd_back()
	ft_lstadd_back(&lst1, lst3);
	tmp = ft_lstlast(lst1);
	// testing if it works
	printf("The last list is: %s\n", (char *)tmp->content); 
	return (0);
} */

// DESCRIPTION
/* Adds the node ’new’ at the end of the list.
 */
