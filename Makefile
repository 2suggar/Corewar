# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 18:17:03 by lcutjack          #+#    #+#              #
#    Updated: 2019/11/16 21:19:00 by lcutjack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: liba asmbl virt

liba:
	@echo "Compiling libft"
	@make -C libft/

asmbl:
	@echo "Compiling asm"
	@make -C Assembler/

virt:
	@echo "Сompiling corewar"
	@make -C VM/

clean:
	@make -C libft/ clean
	make -C Assembler/ clean
	make -C VM/ clean

fclean: clean
	@make -C libft/ fclean
	make -C Assembler/ fclean
	make -C VM/ fclean

re: fclean all

.PHONY: all clean fclean
