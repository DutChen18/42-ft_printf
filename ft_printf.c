#include "ft_printf.h"
#include "libft/libft.h"

static int
	ft_print_pad(t_sink *sink, t_flags *flags, const char *str, size_t size)
{
	char	ch;

	if (flags->flags & ft_printf_left)
		if (ft_xwrite(sink, str, size) < 0)
			return (-1);
	ch = ' ';
	if (~flags->flags & ft_printf_left)
		if ((flags->flags & ft_printf_zero) && flags->precision < 0)
			ch = '0';
	while (flags->width - size > 0)
	{
		if (ft_xwrite(sink, &ch, 1) < 0)
			return (-1);
		size += 1;
	}
	if (~flags->flags & ft_printf_left)
		if (ft_xwrite(sink, str, size) < 0)
			return (-1);
	return (0);
}

static int
	ft_print(t_sink *sink, t_flags *flags, va_list *args)
{
	const char	*str;

	str = va_arg(*args, const char *);
	return (ft_print_pad(sink, flags, str, ft_strlen(str)));
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
	sink.fd = 0;
	size = ft_vxprintf(&sink, fmt, &args);
	va_end(args);
	return (size);
}
