#include "ft_printf.h"
#include <unistd.h>

int
	ft_printf_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

int
	ft_printf_write(t_sink *sink, const char *str, int size)
{
	return (write(sink->fd, str, size));
}

int
	ft_printf_repeat(t_sink *sink, char ch, int size)
{
	char	buf[256];
	int		i;

	i = 0;
	while (i < 256)
	{
		buf[i] = ch;
		i += 1;
	}
	i = 0;
	while (size - i > 256)
	{
		if (ft_printf_write(sink, buf, 256) < 0)
			return (-1);
		i += 256;
	}
	if (i < size)
	{
		if (ft_printf_write(sink, buf, size - i) < 0)
			return (-1);
		i += size - i;
	}
	return (i);
}
