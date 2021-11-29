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
	(void) sink;
	return (write(1, str, size));
}

int
	ft_printf_repeat(t_sink *sink, char ch, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_printf_write(sink, &ch, 1) < 0)
			return (-1);
		i += 1;
	}
	if (0 < size)
		return (size);
	return (0);
}
