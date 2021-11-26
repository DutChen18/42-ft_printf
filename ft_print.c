#include "ft_printf.h"
#include <stdlib.h>

static const char *const	g_charsets[] = {
	"0123456789",
	"0123456789abcdef",
	"0123456789ABCDEF"
};

static const size_t			g_bases[] = {
	10,
	16,
	16
};

static void
	ft_itoa2(char **buf, size_t nbr, const char *charset, size_t base)
{
	if (nbr == 0)
		return ;
	ft_itoa2(buf, nbr / base, charset, base);
	*buf -= 1;
	**buf = charset[nbr % base];
}

static int
	ft_get_num(size_t *nbr, int *sign, t_flags *flags, va_list *args)
{
	*sign = 0;
	if (flags->format == 'd' || flags->format == 'i')
	{
		*sign = va_arg(*args, int);
		*nbr = *sign;
		return (0);
	}
	else if (flags->format == 'p')
	{
		*nbr = (size_t) va_arg(*args, void *);
		return (1);
	}
	*nbr = va_arg(*args, unsigned int);
	if (flags->format == 'u')
		return (0);
	if (flags->format == 'x')
		return (1);
	return (2);
}

int
	ft_print_nbr(t_sink *sink, t_flags *flags, va_list *args)
{
	char	buf[256];
	char	*ptr;
	size_t	tmp;
	int		sign;
	int		type;

	type = ft_get_num(&tmp, &sign, flags, args);
	ptr = buf + 256;
	ft_itoa2(&ptr, tmp, g_charsets[type], g_bases[type]);
	tmp = buf + 256 - ptr;
	if (flags->precision >= 0 && (size_t) flags->precision > tmp)
		tmp = flags->precision;
	if (g_bases[type] == 16)
		if (flags->format == 'p' || (flags->flags & ft_printf_alt))
			tmp += 2;
	return (0);
}

int
	ft_print_str(t_sink *sink, t_flags *flags, va_list *args)
{
	char		ch;
	const char	*str;
	size_t		len;

	len = 1;
	str = "%";
	if (flags->format == 'c')
	{
		ch = va_arg(*args, int);
		str = &ch;
	}
	else if (flags->format == 's')
	{
		str = va_arg(*args, const char *);
		if (str == NULL)
			str = "(null)";
		len = 0;
		while (str[len])
			len += 1;
		if (flags->precision >= 0 && (size_t) flags->precision < len)
			len = flags->precision;
	}
	return (ft_xwrite_pad(sink, flags, str, len));
}
