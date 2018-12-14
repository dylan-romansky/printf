# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dromansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 14:20:44 by dromansk          #+#    #+#              #
#    Updated: 2018/12/13 15:15:21 by dromansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

INCLUDES = -I ./libft/includes

LIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	gcc -o $(NAME) main.c printf.c $(INCLUDES) $(LIB)

clean:
	rm -rf $(NAME)

re: clean all
