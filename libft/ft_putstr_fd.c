#include "libft.h"
#include <unistd.h>

void
	ft_putstr_fd(char *str, int fd)
{
	if (FT_SAFE >= 1 && str == NULL)
		return ;
	write(fd, str, ft_strlen(str));
}
