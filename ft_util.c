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
	ft_xwrite_rep(t_sink *sink, char ch, int size)
{
	while (size > 0)
	{
		if (ft_xwrite(sink, &ch, 1) < 0)
			return (-1);
		size -= 1;
	}
	return (0);
}

int
	ft_xwrite_pad(t_sink *sink, t_flags *flags, const char *str, size_t size)
{
	char	ch;

	if (flags->flags & ft_printf_zero)
		ch = '0';
	if (~flags->flags & ft_printf_left)
		if (ft_xwrite_rep(sink, ch, flags->width - size) < 0)
			return (-1);
	if (ft_xwrite(sink, str, size) < 0)
		return (-1);
	if (flags->flags & ft_printf_left)
		if (ft_xwrite_rep(sink, ' ', flags->width - size) < 0)
			return (-1);
	return (0);
}
