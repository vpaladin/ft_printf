#include "ft_printf.h"

static int	convert_dot(char *format, int *index)
{
	int		len;
	char	*start;
	int		res;
	char	*tmp;

	len = 0;
	start = format + *index;
	if (format[*index] == '.')
	{
		*index = *index + 1;
		tmp = ++start;
	}
	else
		tmp = start;
	while (ft_isdigit(*start++) == 1)
		len++;
	start = ft_substr(tmp, 0, len);
	if (start == NULL)
		return (-1);
	res = ft_atoi(start);
	free(start);
	*index += len;
	return (res);
}

static int	parse_dot(va_list args, t_flag **flags, int index, char *format)
{
	(*flags)->dot = 1;
	if ((*flags)->zero == 1)
		(*flags)->dot_char = 1;
	if (format[++index] == '*')
	{
		(*flags)->precision = va_arg(args, int);
		if ((*flags)->precision < 0 && (*flags)->zero == 1)
			(*flags)->zero = 1;
		else
			(*flags)->zero = 0;
		index++;
	}
	else
	{
		(*flags)->precision = convert_dot(format, &index);
		if ((*flags)->precision == -1)
			return (-1);
		(*flags)->zero = 0;
	}
	return (index);
}

static int	parse_minus(t_flag **flags, int index)
{
	(*flags)->minus = 1;
	(*flags)->zero = 0;
	index++;
	return (index);
}

int	parse_helper(int index, t_flag **flags, va_list args)
{
	(*flags)->width = va_arg(args, int);
	if ((*flags)->width < 0 && !(*flags)->dot)
	{
		(*flags)->minus = 1;
		(*flags)->zero = 0;
		(*flags)->width = -(*flags)->width;
	}
	index++;
	return (index);
}

int	parser_flags(va_list args, char *format, int index, t_flag *flags)
{
	while (ft_isalpha(format[index]) != 1)
	{
		if (format[index] == '0' && !flags->width && !flags->minus)
		{
			flags->zero = 1;
			index++;
		}
		else if (ft_isdigit(format[index]) == 1)
			flags->width = convert_dot(format, &index);
		else if (format[index] == '.')
			index = parse_dot(args, &flags, index, format);
		else if (format[index] == '-')
			index = parse_minus(&flags, index);
		else if (format[index] == '*')
			index = parse_helper(index, &flags, args);
		else if (format[index] == '%' || format[index] == '\0')
			break ;
		else
			index++;
	}
	flags->types = format[index];
	index++;
	return (index);
}
