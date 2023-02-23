/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:07:47 by agomez-u          #+#    #+#             */
/*   Updated: 2023/02/23 19:52:25 by agomez-u         ###   ########.fr       */
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
