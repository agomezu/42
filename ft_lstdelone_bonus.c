/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:49:28 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/17 13:50:50 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

// TEST
/* void	delone(void *content)
{
	if (content)
		content = NULL;
}

int	main(void)
{
	t_list	*lst;
	lst = ft_lstnew("One");
	printf("Content of list: %s\n", (char *)lst->content);
	ft_lstdelone(lst, delone);
	printf("After using ft_lstdelone() the memory is freed.\n");
	return (0);
} */

// DESCRIPTION
/* Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed.
 */
