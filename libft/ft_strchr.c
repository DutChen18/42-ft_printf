#include "libft.h"

char
	*ft_strchr(const char *str, int ch)
{
	while (1)
	{
		if (*str == (char) ch)
			return ((char *) str);
		if (!*str)
			return (NULL);
		str += 1;
	}
}
