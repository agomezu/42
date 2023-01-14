#include <unistd.h>

int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	if (( c >= '0' && c <= '9'))
		return true;
	else
		return false;
}
