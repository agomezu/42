/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:19:00 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:43:32 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// TEST
/*int	main(void)
{
	t_list	*lst;
	t_list	*newlst;

	lst = ft_lstnew((char *)"element1");
	newlst = ft_lstnew((char *)"element2");
	lst->next = newlst;
	printf("Showing elements per list ordering:\n");
	printf("->\t%s\n->\t%s\n", 
		(char *)lst->content, (char *)lst->next->content);
	printf("\nExecuting ft_lstadd_front() instead...");
	ft_lstadd_front(&lst, newlst);
	printf("\n\nShowing elements per list ordering:\n");
	printf("->\t%s\n->\t%s\n",
		(char *)lst->content, (char *)lst->next->content);
	return (0);
}
*/

// DESCRIPTION
/* Adds the node ’new’ at the beginning of the list.
 *
 * In other words, this function inserts a new element
 * at the beginning of the linked list, pushing
 * the existing elements one position down the list.
 *
 * By doing so, the new element new becomes the new
 * head of the list 'lst'.
 */
