#include "ft_printf.h"
#include <limits.h>

static int
	parse_flags(const char **fmt)
{
	int	flags;

	flags = 0;
	while (1)
	{
		if (**fmt == '-')
			flags |= ft_printf_left;
		else if (**fmt == '+')
			flags |= ft_printf_sign;
		else if (**fmt == ' ')
			flags |= ft_printf_space;
		else if (**fmt == '#')
			flags |= ft_printf_alt;
		else if (**fmt == '0')
			flags |= ft_printf_zero;
		else
			return (flags);
		*fmt += 1;
	}
}

static int
	parse_int(const char **fmt, va_list *args)
{
	int	v;

	if (**fmt == '*')
	{
		*fmt += 1;
		v = va_arg(*args, int);
		if (v < 0)
			return (INT_MAX);
		return (v);
	}
	v = 0;
	while (**fmt >= '0' && **fmt <= '9')
	{
		if (v > INT_MAX / 10 || (v * 10 > INT_MAX - (**fmt - '0')))
			return (INT_MAX);
		v = v * 10 + (**fmt - '0');
		*fmt += 1;
	}
	return (v);
}

int
	ft_parse(t_flags *flags, const char **fmt, va_list *args)
{
	flags->flags = parse_flags(fmt);
	flags->width = parse_int(fmt, args);
	if (flags->width == INT_MAX)
		return (-1);
	flags->precision = -1;
	if (**fmt == '.')
	{
		*fmt += 1;
		flags->precision = parse_int(fmt, args);
		if (flags->precision == INT_MAX)
			return (-1);
	}
	flags->format = **fmt;
	*fmt += 1;
	return (0);
}
