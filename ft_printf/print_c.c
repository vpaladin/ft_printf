#include "ft_printf.h"

static int	width_c(t_flag flag)
{
	int	i;

	i = 0;
	if (flag.dot_char == 1)
		flag.zero = 1;
	while (flag.width > 0)
	{
		if (flag.zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		flag.width--;
		i++;
	}
	return (i);
}

int	print_c(t_flag flag, va_list args)
{
	char	s;
	int		i;

	i = 1;
	if (flag.types == '%')
		s = '%';
	else
		s = va_arg(args, int);
	if (flag.minus)
	{
		flag.width -= 1;
		ft_putchar(s);
		i += width_c(flag);
	}
	else
	{
		flag.width -= 1;
		i += width_c(flag);
		ft_putchar(s);
	}
	return (i);
}
