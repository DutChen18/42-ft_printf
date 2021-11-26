#include "libft.h"
#include <unistd.h>

void
	ft_putchar_fd(char ch, int fd)
{
	write(fd, &ch, 1);
}
