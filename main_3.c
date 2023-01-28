#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int	fd;
	char	s[] = "hello world";

	fd = open("main3.txt", O_WRONLY | O_CREAT, 0644);
	ft_putendl_fd(s, fd);
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
}
