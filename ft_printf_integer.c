#include "ft_printf.h"

static void
	ft_printf_atoi(char **buf, size_t value, const char *charset, size_t base)
{
	if (value >= base)
		ft_printf_atoi(buf, value / base, charset, base);
	if (value != 0)
	{
		**buf = charset[value % base];
		*buf += 1;
	}
}

static void
	ft_printf_init(int *precision, int *size, int a_size, int b_size)
{
	if (*precision < 0)
		*precision = 1;
	if (*precision > a_size)
		*size = *precision + b_size;
	else
		*size = a_size + b_size;
}

static int
	ft_printf_pad(t_sink *sink, t_flags *flags, const char *a, const char *b)
{
	int	precision;
	int	a_size;
	int	b_size;
	int	size;
	int	tmp;

	a_size = ft_printf_strlen(a);
	b_size = ft_printf_strlen(b);
	precision = flags->precision;
	ft_printf_init(&precision, &size, a_size, b_size);
	tmp = " 0"[flags->zero && flags->precision < 0];
	if (!flags->left && ft_printf_repeat(sink, tmp, flags->width - size) < 0)
		return (-1);
	if (ft_printf_write(sink, b, b_size) < 0)
		return (-1);
	if (ft_printf_repeat(sink, '0', precision - a_size) < 0)
		return (-1);
	if (ft_printf_write(sink, a, a_size) < 0)
		return (-1);
	if (flags->left && ft_printf_repeat(sink, ' ', flags->width - size) < 0)
		return (-1);
	if (flags->width > size)
		return (flags->width);
	return (size);
}

int
	ft_printf_int(t_sink *sink, t_flags *flags, int value)
{
	char	buf[256];
	char	*ptr;

	buf[255] = '\0';
	ptr = buf + 255;
	if (value < 0)
		ft_printf_atoi(&ptr, -value, "0123456789", 10);
	if (value >= 0)
		ft_printf_atoi(&ptr, value, "0123456789", 10);
	if (flags->space && value >= 0)
		return (ft_printf_pad(sink, flags, ptr, " "));
	if (flags->sign && value >= 0)
		return (ft_printf_pad(sink, flags, ptr, "+"));
	if (value < 0)
		return (ft_printf_pad(sink, flags, ptr, "-"));
	return (ft_printf_pad(sink, flags, ptr, ""));
}

int
	ft_printf_pos(t_sink *sink, t_flags *flags, size_t value)
{
	char		buf[256];
	char		*ptr;

	buf[255] = '\0';
	ptr = buf + 255;
	if (flags->format == 'u')
		ft_printf_atoi(&ptr, value, "0123456789", 10);
	if (flags->format == 'x' || flags->format == 'p')
		ft_printf_atoi(&ptr, value, "0123456789abcdef", 16);
	if (flags->format == 'X')
		ft_printf_atoi(&ptr, value, "0123456789ABCDEF", 16);
	if (flags->format == 'x' && flags->alt)
		return (ft_printf_pad(sink, flags, ptr, "0x"));
	if (flags->format == 'X' && flags->alt)
		return (ft_printf_pad(sink, flags, ptr, "0X"));
	if (flags->format == 'p')
		return (ft_printf_pad(sink, flags, ptr, "0x"));
	return (ft_printf_pad(sink, flags, ptr, ""));
}
