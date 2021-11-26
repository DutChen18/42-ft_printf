#include "libft.h"

char
	*ft_strrchr(const char *str, int ch)
{
	char	*res;

	res = NULL;
	while (1)
	{
		if (*str == (char) ch)
			res = (char *) str;
		if (!*str)
			return (res);
		str += 1;
	}
}
