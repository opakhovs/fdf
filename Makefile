# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/02 17:06:02 by opakhovs          #+#    #+#              #
#    Updated: 2018/04/02 17:06:05 by opakhovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

LDLIBS = -lm -lmlx -framework OpenGL -framework AppKit

GNL = gnl/get_next_line.c

FDF =  src/main.c src/useful.c src/draw.c src/handle.c src/draw2.c

LIBFT = libft/libft.a

COMPILED = $(FDF:.c=.o) $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C ./libft
	@gcc $(FLAGS) -o $(NAME) $(COMPILED) $(LIBFT) $(LDLIBS)

clean:
	@make clean -C ./libft
	@/bin/rm -f $(COMPILED)

fclean: clean
	@make fclean -C ./libft
	@/bin/rm  -f $(NAME)

re: fclean all
