#include "ft_printf.h"

int	width_s(t_flag flag)
{
	int	len;

	len = 0;
	while (flag.width > 0)
	{
		if (flag.zero)
		{
			ft_putchar('0');
			len++;
		}
		else
		{
			ft_putchar(' ');
			len++;
		}
		flag.width--;
	}
	return (len);
}

int	print_str(char *str, int len)
{
	int	res;

	res = 0;
	while (len && str[res])
	{
		ft_putchar(str[res]);
		res++;
		len--;
	}
	return (res);
}

int	print_s2(t_flag flag, char *s, int len, int res)
{
	if (flag.minus)
	{
		len = print_str(s, len);
		flag.width -= len;
		len += width_s(flag);
	}
	else
	{
		flag.width -= len;
		len = width_s(flag);
		len += print_str(s, res);
	}
	return (len);
}

int	print_s(t_flag flag, va_list args)
{
	int		len;
	char	*s;
	int		res;

	s = va_arg(args, char *);
	if (s == 0)
		s = "(null)";
	len = (int)ft_strlen(s);
	if (flag.precision > len)
		flag.precision = len;
	else if (flag.dot && flag.precision >= 0)
		len = flag.precision;
	res = len;
	len = print_s2(flag, s, len, res);
	return (len);
}
