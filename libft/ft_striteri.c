#include "libft.h"

void
	ft_striteri(char *str, void (*func)(unsigned int, char*))
{
	unsigned int	i;

	if (FT_SAFE >= 1 && str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		func(i, str + i);
		i += 1;
	}
}
