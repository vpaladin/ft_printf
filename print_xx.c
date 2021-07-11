#include "ft_printf.h"

static int	conv_ex(int nb, t_flag flag)
{
	if (nb >= 10)
	{
		if (flag.types == 'x' || flag.types == 'p')
			return (nb - 10 + 'a');
		else
			return (nb - 10 + 'A');
	}
	else
		return (nb + '0');
}

char	*itoa_base(unsigned long long value, t_flag flag)
{
	int					i;
	char				*str;
	unsigned long long	tmp;

	i = 0;
	tmp = value;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % 16;
		str[i] = conv_ex(tmp, flag);
		value /= 16;
		i--;
	}
	return (str);
}

int	print_xx2(int i, char *s, t_flag flag)
{
	int	tmp;

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
	return (i);
}

int	print_xx(t_flag flag, va_list args)
{
	int		i;
	char	*s;
	long	arg;

	arg = va_arg(args, unsigned int);
	if (arg == 0 && flag.precision == 0 && flag.dot == 1)
	{
		arg = width_d(flag, "");
		return (arg);
	}
	s = itoa_base(arg, flag);
	i = (int)ft_strlen(s);
	i = print_xx2(i, s, flag);
	free(s);
	return (i);
}
