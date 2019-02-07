# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:53:52 by dromansk          #+#    #+#              #
#    Updated: 2019/02/05 15:32:00 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./printf/src/*.c ./printf/src/conversion/*.c \
./printf/src/parsing_and_handling/*.c ./printf/src/flags/*.c \
./printf/src/formatting_and_helpers/*.c ./printf/libft/*.c \
./printf/src/colours/*.c

I = -I ./printf/includes

O = *.o

L = -L ./ -lftprintf

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(I) $(SRCS) -c
	ar rcs $(NAME) $(O)
	ranlib $(NAME)

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

reclean: re
	make clean

compile: reclean
	gcc main.c $(I) $(L)

test: reclean
	compile
	./a.out

run: clean
	compile
	./a.out
