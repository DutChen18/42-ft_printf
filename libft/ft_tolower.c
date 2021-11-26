#include "libft.h"

int
	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch += 'a' - 'A';
	return (ch);
}
