/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:18:30 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:43:19 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstnew(void *content)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(*newlst));
	if (!newlst)
		return (0);
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}

// TEST
/*int	main(void)
{
	char	str[] = "element of a list";
	t_list	*newlst;

	printf("Let's create a new node.");
	newlst = ft_lstnew(str);
	if (newlst)
	{
		printf("\nDone.\nNow let's call it...\n");
		printf("-> %s\n", (char *)newlst->content);
	}
	return (0);
}*/

// DESCRIPTION
/* Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’. The variable
 * ’next’ is initialized to NULL.
 */
