#include "libft.h"

char
	test_function(unsigned int i, char c)
{
	if (i % 2 == 0)
		if (c >= 'a' && c <= 'z')
			c = c - 32;
	return (c);
}

int
	main(void)
{
	char	*str = "hello world";
	char	*result = ft_strmapi(str, test_function);
	printf("%s\n", result);
	free(result);
	return (0);
}
