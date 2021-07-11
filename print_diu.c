#include "ft_printf.h"

int	widt_d2(t_flag flag, int len)
{
	while (flag.width > 0)
	{
		if (flag.zero)
		{
			len++;
			ft_putchar('0');
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

int	width_d(t_flag flag, char *s)
{
	int	len;

	len = 0;
	if (flag.sign_arg == 1 && flag.zero)
	{
		ft_putchar('-');
		len++;
	}
	if (flag.width < flag.precision)
		return (len);
	if (flag.precision < (int)ft_strlen(s))
		flag.precision = (int)ft_strlen(s);
	flag.width -= flag.precision;
	if (flag.types == 'p')
		flag.width -= 2;
	len = widt_d2(flag, len);
	return (len);
}

int	precision_d(t_flag flag, char *s)
{
	int	k;

	k = 0;
	if (flag.sign_arg == 1 && flag.zero != 1)
	{
		ft_putchar('-');
		k++;
	}
	if (flag.precision)
	{
		flag.precision -= (int)ft_strlen(s);
		while (flag.precision > 0)
		{
			k++;
			ft_putchar('0');
			flag.precision--;
		}
	}
	return (k);
}

int	diu_helper(long arg, t_flag flag)
{
	char	*s;
	int		i;
	int		tmp;

	s = ft_itoa(arg);
	if (s == 0)
		return (-1);
	i = (int)ft_strlen(s);
	if (flag.minus)
	{
		i += precision_d(flag, s);
		ft_putstr(s);
		i += width_d(flag, s);
	}
	else
	{
		tmp = width_d(flag, s);
		i += precision_d(flag, s) + tmp;
		ft_putstr(s);
	}
	free(s);
	return (i);
}

int	print_diu(t_flag flag, va_list args)
{
	long	arg;

	if (flag.types == 'u')
		arg = va_arg(args, unsigned int);
	else
		arg = va_arg(args, int);
	if (arg == 0 && flag.precision == 0 && flag.dot == 1)
	{
		arg = width_d(flag, "");
		return (arg);
	}
	if (arg < 0)
	{
		arg = -arg;
		flag.sign_arg = 1;
		flag.width--;
	}
	return (diu_helper(arg, flag));
}
