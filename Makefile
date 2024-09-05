# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 18:17:13 by jormoral          #+#    #+#              #
#    Updated: 2024/08/30 17:33:18 by jormoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = Libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a 
MLX_FLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC = main.c \
init_values.c \
draw.c \
set_map.c \
check_map.c \
free_utils.c \
color_utils.c \

CC = clang -Wall -Wextra -Werror -g -fsanitize=address

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(MLX42)
	$(CC) $(OBJ) $(LIBFT) $(MLX42) $(MLX_FLAGS) -o $@

$(LIBFT) :
	make -C "Libft"

$(MLX42) :
	cmake -B MLX42/build -S ./MLX42
	cmake --build MLX42/build -j4

%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C "Libft" clean
	make clean -C ./MLX42/build

fclean : clean
	rm -f $(NAME)
	make -C "Libft" fclean
	make clean -C ./MLX42/build

norm: 
	norminette $(SRC)


re : fclean all

.PHONY : all clean fclean re