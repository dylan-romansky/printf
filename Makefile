# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:53:52 by dromansk          #+#    #+#              #
#    Updated: 2019/01/16 15:43:05 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./printf/src/*.c ./printf/src/conversion/*.c \
./printf/src/parsing_and_handling/*.c ./printf/src/flags/*.c \
./printf/src/formatting_and_helpers/*.c ./libft/src/*.c

I = -I ./libft/includes -I ./printf/includes

O = *.o

L = -L ./ -lftprintf

all: $(NAME)

$(NAME):
	gcc $(I) $(SRCS) -c
	ar rcs $(NAME) $(O)
	ranlib $(NAME)

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

reclean: re
	rm -rf $(O)

test: reclean
	gcc main.c -I ./printf/includes $(L)
	./a.out

run:
	gcc main.c -I ./printf/include $(L)
	./a.out
