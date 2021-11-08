#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	t;

	i = 0;
	length = 0;
	while (str[length])
		length++;
	length--;
	while (i < length)
	{
		t = str[i];
		str[i] = str[length];
		str[length] = t;
		length--;
		i++;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	int		i;
	int		len;
	char	*str;
	long	res;

	i = 0;
	res = n;
	len = ft_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (res < 0)
		res = -res;
	if (res == 0)
		str[i++] = '0';
	while (res != 0)
	{
		str[i++] = (res % 10) + '0';
		res /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
