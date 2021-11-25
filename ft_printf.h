#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>

typedef struct s_flags	t_flags;
typedef struct s_sink	t_sink;

enum
{
	ft_printf_left	= 0x01,
	ft_printf_zero	= 0x02,
	ft_printf_alt	= 0x04,
	ft_printf_space	= 0x08,
	ft_printf_sign	= 0x10
};

enum
{
	ft_printf_fd
};

struct s_flags
{
	int	flags;
	int	width;
	int	precision;
	int	format;
};

struct s_sink
{
	int	type;
	int	size;
	int	fd;
};

int	ft_parse(t_flags *flags, const char **fmt, va_list *args);
int	ft_xwrite(t_sink *sink, const char *str, size_t size);
int	ft_printf(const char *fmt, ...);

#endif
