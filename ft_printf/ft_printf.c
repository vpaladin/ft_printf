#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flag	*flags;
	int		res;

	if (!format[0])
	{
		write(1, "", 0);
		return (0);
	}
	if (ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	flags = malloc(sizeof(t_flag));
	if (!flags)
		return (-1);
	ft_bzero(flags, sizeof(t_flag));
	va_start(args, format);
	res = parse_input(args, flags, format);
	va_end(args);
	free(flags);
	return (res);
}

int	input_helper(int index, char *format, int *tmp)
{
	index++;
	if (format[index] == ' ')
	{
		ft_putchar(' ');
		index++;
	}
	*tmp = index;
	return (index);
}

void	input_helper_part_two(int *length, int *index, const char *format)
{
	ft_putchar(format[*index]);
	(*length)++;
	(*index)++;
}

int	parse_input(va_list args, t_flag *flags, const char *format)
{
	int	digit[3];

	digit[0] = 0;
	digit[1] = 0;
	while (format[digit[0]] != 0)
	{
		if (format[digit[0]] != '%')
			input_helper_part_two(&digit[1], &digit[0], format);
		else
		{
			digit[0] = input_helper(digit[0], (char *)format, &digit[2]);
			digit[0] = parser_flags(args, (char *)format, digit[0], flags);
			if (digit[0] == -1)
				return (-1);
			if (flags->types)
				digit[1] += print_arguments(args, flags->types, *flags);
			else
			{
				digit[1] += 1;
				digit[0] = digit[2];
			}
			ft_bzero(flags, sizeof(t_flag));
		}
	}
	return (digit[1]);
}
