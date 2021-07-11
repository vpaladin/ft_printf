#include "ft_printf.h"

int	print_width(t_flag *flag, int len)
{
	while ((*flag).width > 0)
	{
		if ((*flag).zero)
		{
			len++;
			ft_putchar('0');
		}
		else
		{
			ft_putchar(' ');
			len++;
		}
		(*flag).width--;
	}
	return (len);
}

int	width_p(t_flag flag, char *s)
{
	int	len;

	len = 0;
	if (flag.sign_arg == 1 && flag.zero)
	{
		ft_putchar('-');
		len++;
	}
	if (flag.width < flag.precision)
		return (0);
	if (flag.precision < (int)ft_strlen(s))
		flag.precision = (int)ft_strlen(s);
	flag.width -= flag.precision;
	if (flag.types == 'p')
		flag.width -= 2;
	len = print_width(&flag, len);
	return (len);
}

int	print_p2(t_flag flag, int i, char *s, int arg)
{
	int	tmp;

	if (flag.zero)
	{
		ft_putstr("0x");
		tmp = width_p(flag, s);
	}
	else
	{
		if (arg == 0 && flag.precision == 0 && flag.dot == 1)
		{
			flag.width++;
			i--;
		}
		tmp = width_p(flag, s);
		ft_putstr("0x");
	}
	i += precision_d(flag, s) + tmp;
	if (!(arg == 0 && flag.precision == 0 && flag.dot == 1))
		ft_putstr(s);
	return (i);
}

int	print_p3(t_flag flag, int i, char *s)
{
	i += precision_d(flag, s);
	ft_putstr("0x");
	if (flag.dot && flag.precision == 0)
		ft_putchar(' ');
	else
		ft_putstr(s);
	i += width_p(flag, s);
	return (i);
}

int	print_p(t_flag flag, va_list args)
{
	int					i;
	char				*s;
	unsigned long long	arg;

	arg = va_arg(args, unsigned long long);
	if (arg == 0 && flag.precision == 0 && flag.dot == 1 && !flag.width)
	{
		ft_putstr("0x");
		return (2);
	}
	s = itoa_base(arg, flag);
	if (s == NULL)
		return (-1);
	i = (int)ft_strlen(s) + 2;
	if (flag.minus)
		i = print_p3(flag, i, s);
	else
		i = print_p2(flag, i, s, arg);
	free(s);
	return (i);
}
