# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaktion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 18:07:37 by olaktion          #+#    #+#              #
#    Updated: 2018/08/28 18:07:40 by olaktion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC	 = main.c\
		hook.c\
		   mandelbrot.c\
		   julia.c\
		   tools.c\
		   bship.c\

INC = fractol.h


CFLAGS = -Wall -Wextra -Werror -I
OBJ = $(SRC:.c=.o)
LIB = ./libft/

MLX = -lmlx -framework AppKit -framework OpenGl -O3

DIR_H = ./includes/

all: $(NAME)

makelib:
	@make -C ./libft/

libclean:
	@make -C ./libft/ clean

libfclean:
	@make -C ./libft/ fclean

$(NAME): $(OBJ) makelib
	@gcc -I $(INC) $(OBJ) -o $(NAME) -L $(LIB) -lft $(MLX)
	@echo "Compilation of Fractol:	\033[1;32mOK\033[m"

%.o: %.c
	@gcc -I $(INC) -c $< -o $@

clean: libclean
	@rm -f $(OBJ)
	@echo "Fractol: Removing Objs : \033[1;32mOK\033[m"

fclean: libfclean clean
	@rm -f $(NAME)
	@echo "Removing Fractol : \033[1;32mOK\033[m"

re: fclean all

.NOTPARALLEL: all clean fclean re
.PHONY: all clean fclean re

