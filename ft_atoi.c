/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:27 by agomez-u          #+#    #+#             */
/*   Updated: 2023/03/21 20:47:31 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	isneg;
	int	i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

int
	ft_atoi_1(const char *str)
{
	size_t			i;
	const char	*ptr;
	unsigned int	sgn;
	int				res;

	if (!str)
		return (0);
	i = 0;
	ptr = str;
	sgn = 1;
	res = 0;
	while (ptr[i] == ' ' || (ptr[i] >= '\t' && ptr[i] <= '\r'))
		++i;
	if (ptr[i] == '+')
		++i;
	else if (ptr[i] == '-')
	{
		sgn = -1;
		++i;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res = (res * 10) + (ptr[i] - '0');
		++i;
	}
	return ((int)(res * sgn));
}

// TEST
/*int	main(void)
{
	char	str[] = "    -12348";
	char	str1[] = "    -12348";

	printf("In this program we're going to use our atoi function.\n");
	printf("The string to be converted as integer is\n-> \t%s\n", str);
	printf("\n\n------------------------------------------\n\n");
	printf("After using the function, the result is:\n-> \t"
		"%d\n", ft_atoi(str));

	printf("\n\n\nWith the real atoi function, the result is:\n->\t");
	printf("%d\n", atoi(str));
	return (0);
}
*/

// DESCRIPTION
/* The atoi() function converts the initial portion of the string pointed
 * to by nptr to int.  The behavior is the same as
 *
 * 	strtol(nptr, NULL, 10);
 *
 * except that atoi() does not detect errors.
 *
 * The atol() and atoll() functions behave the  same  as  atoi(),  except
 * that  they  convert  the initial portion of the string to their return
 * type of long or long long.
 *
 * Atoi() return the converted value.
 */
