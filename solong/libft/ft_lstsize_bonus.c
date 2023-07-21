/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:07:47 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/14 19:49:11 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_lstsize(t_list *lst)
{
	struct s_list	*ptr;
	size_t			i;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		++i;
	}
	return (i);
}

// TEST
/*int	main(void)
{
	t_list	*head = NULL;
	t_list	*second = NULL;
	t_list	*third = NULL;
	int	n;

	// Allocate 3 nodes in the linked list
	// Assign values to each node
	head = ft_lstnew("This is the first node");
	second = ft_lstnew("This is the second node");
	third = ft_lstnew("This is the third node");
	head->next = second;
	second->next = third;
	n = (int)ft_lstsize(head);
	printf("Number of nodes in the list: %d\n", n);
	free(head);
	free(second);
	free(third);
	return (0);
}
*/

// DESCRIPTION
/* Counts the number of nodes in a list.
 */
