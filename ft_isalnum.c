#include "libft.h"

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return true;
	else
		return false;
}
