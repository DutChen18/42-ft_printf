#include "ft_printf.h"
#include <unistd.h>

int
	ft_xwrite(t_sink *sink, const char *str, size_t size)
{
	sink->size += size;
	if (sink->type == ft_printf_fd)
	{
		if (write(sink->fd, str, size) >= 0)
			return (0);
	}
	return (-1);
}

int
	ft_xwrite_rep(t_sink *sink, char ch, size_t size)
{
	while (size > 0)
	{
		if (ft_xwrite(sink, &ch, 1) < 0)
			return (-1);
		size -= 1;
	}
	return (0);
}
