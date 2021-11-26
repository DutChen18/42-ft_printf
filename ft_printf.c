#include "ft_printf.h"
#include <unistd.h>

static int
	ft_print(t_sink *sink, t_flags *flags, va_list *args)
{
	(void) sink;
	(void) flags;
	(void) args;
	return (-1);
}

static int
	ft_vxprintf(t_sink *sink, const char *fmt, va_list *args)
{
	t_flags	flags;

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if (ft_parse(&flags, &fmt, args) < 0)
				return (-1);
			if (ft_print(sink, &flags, args) < 0)
				return (-1);
		}
		else
		{
			if (ft_xwrite(sink, fmt, 1) < 0)
				return (-1);
			fmt += 1;
		}
	}
	return (sink->size);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_sink	sink;
	int		size;

	va_start(args, fmt);
	sink.type = ft_printf_fd;
	sink.size = 0;
	sink.fd = 1;
	size = ft_vxprintf(&sink, fmt, &args);
	va_end(args);
	return (size);
}
