#include "ft_printf.h"
#include <limits.h>

static void
	ft_printf_parse_flags(t_flags *flags, const char **fmt)
{
	flags->left = 0;
	flags->sign = 0;
	flags->space = 0;
	flags->alt = 0;
	flags->zero = 0;
	while (1)
	{
		if (**fmt == '-')
			flags->left = 1;
		else if (**fmt == '+')
			flags->sign = 1;
		else if (**fmt == ' ')
			flags->space = 1;
		else if (**fmt == '#')
			flags->alt = 1;
		else if (**fmt == '0')
			flags->zero = 1;
		else
			return ;
		*fmt += 1;
	}
}

static int
	ft_printf_parse_int(const char **fmt, va_list *args)
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
	ft_printf_parse(t_flags *flags, const char **fmt, va_list *args)
{
	ft_printf_parse_flags(flags, fmt);
	flags->width = ft_printf_parse_int(fmt, args);
	if (flags->width == INT_MAX)
		return (-1);
	flags->precision = -1;
	if (**fmt == '.')
	{
		*fmt += 1;
		flags->precision = ft_printf_parse_int(fmt, args);
		if (flags->precision == INT_MAX)
			return (-1);
	}
	flags->format = **fmt;
	*fmt += 1;
	return (0);
}
