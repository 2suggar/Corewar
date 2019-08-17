# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 16:35:27 by lcutjack          #+#    #+#              #
#    Updated: 2019/08/17 16:14:13 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Wextra -Werror

LIB = ../libft/libft.a
INC = -Iasm.h -I../libft/includes/
SRC = main.c error_msg.c cooking.c
OBJ = $(SRC:.o=.c)


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(INC) -c $(SRC)
	gcc $(OBJ) $(LIB) $(INC) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	
re: fclean all