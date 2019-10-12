# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 16:35:27 by lcutjack          #+#    #+#              #
#    Updated: 2019/10/12 03:23:56 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =asm

FLAGS = -Wall -Wextra -Werror

LIB = ../libft/libft.a
INC = -I../libft/includes/ -I./inc/
SRC = main.c error_msg.c cooking.c reading_code.c basic.c op.c validation.c \
		useful.c writing.c for_valid.c check_arg.c check_com_nam.c \
		to_file.c ft_memcpy_rev.c

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
	gcc $(SRC) $(INC) -o $(NAME) $(LIB)

fclean:
	rm -rf $(NAME) *.o
