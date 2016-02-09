# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vklepper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:16:04 by vklepper          #+#    #+#              #
#    Updated: 2016/02/04 19:16:09 by vklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC = src/main.c src/draw.c src/data.c src/key.c src/mandelbrot.c
OBJ = src/main.o src/draw.o src/data.o src/key.o src/mandelbrot.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) -Ilibft libft/libft.a $(SRC) -lmlx -framework OpenGL -framework AppKit

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all