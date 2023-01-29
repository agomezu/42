#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int	main(void)
{
	int	fd;
	int	n = -123456789;
	//char	s[] = "hello world";

	fd = open("main3.txt", O_WRONLY | O_CREAT, 0644);
	ft_putnbr_fd(n, fd);
	close(fd);
	return (0);
}
