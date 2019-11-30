# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 19:28:38 by bkiehn            #+#    #+#              #
#    Updated: 2019/11/30 16:48:56 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

INC = ./includes

LIBRARY = ../libft

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) -I $(INC) -L ./$(LIBRARY) -lft

objs/%.o: srcs/%.c
	@mkdir -p objs
	@gcc -c $(FLAGS)  $< -o $@ -I $(INC)

debug:
	@gcc -g3 -o $(NAME) $(SRCS) -I $(INC) -L ./$(LIBRARY) -lft

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

## Diff arguments ##

# Write champs from stdin
## e.g CHAMPS = Batman.cor Gangnat.cor
CHAMPS =

# Dump
## e.g DUMP = 2000
DEF_DUMP_FLAG = -d
OURS_DUMP_FLAG = -dump
DUMP =

DEF_NAME = defcorewar
DEF_OUT = def.res
OURS_OUT = ours.res

diff_output: ##Usage: make diff_output DUMP=<dump_cycle> CHAMPS=<champs_arg>
ifeq ($(strip $(CHAMPS)),)
	@echo "No champs given"
	@echo "Result is incorrect"
endif
#Run with not given dump
ifeq ($(strip $(DUMP)),)
	$(NAME) $(CHAMPS) > $(OURS_OUT)
	$(addprefix ./,$(DEF_NAME)) $(CHAMPS) > $(DEF_OUT)
	diff $(OURS_OUT) $(DEF_OUT)
else
	$(NAME) $(OURS_DUMP_FLAG) $(DUMP)  $(CHAMPS) > $(OURS_OUT)
	$(addprefix ./,$(DEF_NAME)) $(DEF_DUMP_FLAG) $(DUMP) $(CHAMPS) > $(DEF_OUT)
	diff $(OURS_OUT) $(DEF_OUT)
endif
## End Diff ##