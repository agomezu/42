/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:46:48 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/29 20:53:29 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstlast(t_list *lst);

t_list
	*ft_lstlast(t_list *lst)
{
	struct s_list *ptr;

	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
