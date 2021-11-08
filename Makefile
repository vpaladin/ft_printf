CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS	= ft_parser.c ft_printf.c printf_utils.c printf_utils2.c print.c \
		print_xx.c print_s.c print_p.c print_diu.c print_c.c
OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

$(NAME) : ${OBJS}
	ar rcs ${NAME} ${OBJS} 

all : ${NAME}

debug:
	$(CC) -g -o ft_printf $(SRCS) 
clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all