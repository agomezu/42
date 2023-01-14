#include "libft.h"
// #include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	str = (char*)b;
	i = 0;
	while ( i < len )
	{
		*(str+i) = (unsigned char)c;
		i++;
	}
	return (str);
}

/* int	main(void)
{
	printf("hello world: %s\n", ft_memset("hello world", 'A', 4));
	return 0;
} */
