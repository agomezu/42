#include <unistd.h>

int	ft_isalpha(int c);

int	ft_isalpha(int c)
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}		
