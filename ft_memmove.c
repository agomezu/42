#include "libft.h"

void	*memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dst + j))
		j++;
	while (i < len)
	{
		*(char*)(dst + j) = *(char*)(src + i);
		j++;
		i++;
	}
	return (dst);
}
