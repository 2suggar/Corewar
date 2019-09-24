# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 16:35:27 by lcutjack          #+#    #+#              #
#    Updated: 2019/09/24 19:54:08 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =asm

FLAGS = -Wall -Wextra -Werror

LIB = ../libft/libft.a
INC = -I../libft/includes/ -I./inc/
SRC = main.c error_msg.c cooking.c reading_code.c basic.c op.c validation.c

OBJ_DIR = obj/
OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

# $(OBJ_DIR)%.o: %.c
# 	@mkdir -p $(OBJ_DIR)
# 	@gcc $(FLAGS) -c $< -o $@ $(INC)

# $(NAME): $(addprefix $(OBJ_DIR),$(OBJ))
# 	gcc $(FLAGS) $(addprefix $(OBJ_DIR), $(OBJ)) $(LIB) $(INC) -o $(NAME)

# clean:
# 	rm -rf obj

# fclean: clean
# 	rm -rf $(NAME)
	
# re: fclean all

# for DEBUG | down below


$(NAME):
	gcc -g $(FLAGS) $(SRC) $(INC) -o $(NAME) $(LIB)

fclean:
	rm -rf $(NAME) *.o
