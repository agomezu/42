/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:01:41 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/20 21:07:36 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}

// TEST
/*void
	lstcontent(void *content)
{
	if (content)
		*((char*)content) = 'a';
}

void
	printlst(t_list *lst)
{
	t_list	*ptr;
	int	n;
	ptr = lst;
	n = 1;
	while (ptr)
	{
		printf("List %d content: %s\n", n++, (char *)ptr->content);
		ptr = ptr->next;
	}
}

int
	main(void)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*lst4;
	
	lst1 = ft_lstnew("a");
	lst2 = ft_lstnew("b");
	lst3 = ft_lstnew("c");
	lst4 = ft_lstnew("d");
	lst1->next = lst2;
	lst2->next = lst3;
	lst3->next = lst4;
	printlst(lst1);
	printf("Calling ft_lstiter(lst1, lstcontent)\n");
	ft_lstiter(lst1, lstcontent);
	printlst(lst1);
	free(lst1);
	free(lst2);
	free(lst3);
	free(lst4);
}
*/

// DESCRIPTION
/* Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 */
