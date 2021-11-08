#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	int				dot;
	char			types;
	int				sign_arg;
	int				dot_char;
}				t_flag;

int		ft_printf(const char *format, ...);
int		parser_flags(va_list args, char *format, int index, t_flag *flags);
int		parse_input(va_list args, t_flag *flags, const char *format);
int		print_arguments(va_list args, char types, t_flag flag);
int		print_s(t_flag flag, va_list args);
int		print_c(t_flag flag, va_list args);
int		print_diu(t_flag flag, va_list args);
int		print_xx(t_flag flag, va_list args);
int		print_p(t_flag flag, va_list args);
int		width_s(t_flag flag);
int		width_d(t_flag flag, char *s);
int		precision_d(t_flag flag, char *s);
int		chek_input(char c);

void	ft_bzero(void *b, size_t len);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
char	*ft_itoa(long n);
char	*itoa_base(unsigned long long value, t_flag flag);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
