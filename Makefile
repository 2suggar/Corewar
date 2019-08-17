NAME = printBin

BLUE = \033[34m
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

make: all

all:
	@gcc *.c -o $(NAME) -I main.h -I libft/includes/ -lft -L./libft/
	@echo "$(BLUE)	We've got it!\n$(RESET)"