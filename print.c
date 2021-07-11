#include "ft_printf.h"

int	print_arguments(va_list args, char types, t_flag flag)
{
	int		i;

	i = 0;
	if (types == 's')
		return (print_s(flag, args));
	if (types == 'c')
		return (print_c(flag, args));
	if (types == 'd' || types == 'i')
		return (print_diu(flag, args));
	if (types == 'p')
		return (print_p(flag, args));
	if (types == 'x' || types == 'X')
		return (print_xx(flag, args));
	if (types == 'u')
		return (print_diu(flag, args));
	if (types == '%')
		return (print_c(flag, args));
	ft_putchar(flag.types);
	return (i);
}

static char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;
	size_t	length;

	length = ft_strlen(src);
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
