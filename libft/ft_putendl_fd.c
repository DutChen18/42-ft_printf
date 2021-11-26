#include "libft.h"

void
	ft_putendl_fd(char *str, int fd)
{
	if (FT_SAFE >= 1 && str == NULL)
		return ;
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
