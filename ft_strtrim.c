/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-u <agomez-u@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:30:16 by agomez-u          #+#    #+#             */
/*   Updated: 2023/01/21 23:19:00 by agomez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char
	*ft_strtrim(char const *s1, char const *set);

// function that sees if character c is inside the string set (the string to be removed from *s1
// i need to know how to do this fucking function because i'm so lost!

static int
	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (true);
		i++;
	}
	return (false)
}

char
	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;	
	char	*str;

	start = 0;
	while (*(s1 + start) && ft_char_in_set(*(s1 + start), set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(*(s1 + (end - 1), set)))
		end--;
	str = (char*)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (0);
	i = 0;	
	while (start < end)
		*(str + i) = *(s1 + start++);
	*(str + i) = '\0';
	return (str);
}
