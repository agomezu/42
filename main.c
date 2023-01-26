/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:58:55 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/26 08:27:21 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	const char	*s = "Hello, world! How are you?";
	char	**arr = ft_split(s, ' ');
	size_t	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
	       i++;
	}	       
}

/* 
 * Esta función main crea una cadena constante s y la pasa a la función ft_split, utilizando el carácter espacio ' ' como separador. Luego, imprime cada elemento del arreglo resultante en una nueva línea utilizando un bucle while.
 */
