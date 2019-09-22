# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 16:35:27 by lcutjack          #+#    #+#              #
#    Updated: 2019/09/22 15:34:42 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =asm

FLAGS = -Wall -Wextra -Werror

LIB = ../libft/libft.a
INC = -Iasm.h op.h -I../libft/includes/
SRC = main.c error_msg.c cooking.c reading_code.c basic.c op.c validation.c
OBJ = $(SRC:.o=.c)


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(INC) -c $(SRC)
	gcc $(OBJ) $(LIB) $(INC)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	
re: fclean all