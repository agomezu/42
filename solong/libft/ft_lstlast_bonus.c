/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:46:48 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/14 19:57:24 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstlast(t_list *lst)
{
	struct s_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

// TEST
/*int	main(void)
{
	t_list	*head = NULL;
	t_list	*second = NULL;
	t_list	*third = NULL;
	t_list	*ptr = NULL;

	head = ft_lstnew("First node");
	second = ft_lstnew("Second node");
	third = ft_lstnew("Third node");
	head->next = second;
	second->next = third;
	ptr = (t_list *)ft_lstlast(head);
	printf("The last node is: %s\n", (char *)ptr->content);
	free(head);
	free(second);
	free(third);
	return (0);
}
*/

// DESCRIPTION
/* Returns the last node of the list.
 */
