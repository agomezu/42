#include "libft.h"
#include <stdlib.h>

void
	*ft_calloc(size_t count, size_t size);

int	main(void)
{
	
void
	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = (void*)malloc(count * size);
	if (!ptr)
		return (0);	
	while (i < count)
	{
		*(char*)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

