NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_putnbr.c ft_printhex.c ft_putvoid.c \
	   ft_putnbr_unsigned.c \

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -src

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
	${RM} ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re