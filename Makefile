# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:53:52 by dromansk          #+#    #+#              #
#    Updated: 2019/01/22 18:18:06 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./printf/src/*.c ./printf/src/conversion/*.c \
./printf/src/parsing_and_handling/*.c ./printf/src/flags/*.c \
./printf/src/formatting_and_helpers/*.c

I = -I ./libft/includes -I ./printf/includes

O = *.o ./libft/*.o

L = -L ./ -lftprintf

all: $(NAME)

$(NAME):
	make -C ./libft/ all
	gcc $(I) $(SRCS) -c
	ar rcs $(NAME) $(O)
	ranlib $(NAME)

clean:
	make -C ./libft/ clean
	rm -rf $(O)

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean all

reclean: re
	make clean

test: reclean
	gcc main.c $(I) $(L)
	./a.out

run: clean
	gcc main.c $(I) $(L)
	./a.out
