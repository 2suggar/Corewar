/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:35:40 by bkiehn            #+#    #+#             */
/*   Updated: 2019/10/24 21:35:44 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	to_string(t_champion *cursors, char flag_body)
{
	int count;

	count = 1;
	ft_printf("-------------------------\n%s", cursors->color);
	ft_printf("number_cursor: %d\nnumber: %d\nname: %s\n",
			cursors->number_cursors, cursors->number, cursors->name);
	ft_printf("comment: %s\n", cursors->comment);
	ft_printf("size: %d\n", cursors->size);
	ft_printf("position: %d\ncarry: %d\ncode_operation: %d\n",
			cursors->position, cursors->carry, cursors->code_operation);
	ft_printf("last_live_in_cycle: %d\ncycle_before_run:"
			" %d\nbytes_for_next_operation: %d\n", cursors->last_live_in_cycle,
			cursors->cycle_before_run, cursors->bytes_for_next_operation);
	ft_printf("Registers:\n");
	while (count <= REG_NUMBER)
	{
		ft_printf("\tREG_%d: %d\n", count, cursors->reg[count]);
		count++;
	}
	if (flag_body)
	{
		ft_printf("Body:\n");
		print_bytes_hex(cursors->body, cursors->size);
	}
	ft_printf("%s-------------------------\n", NO_COLOR);
}

void	print_cursors(t_champion *cursors, char flag_body)
{
	while (cursors != 0)
	{
		cursors->to_string(cursors, flag_body);
		cursors = cursors->next;
	}
}

void	print_rules(t_rules *rules)
{
	ft_printf("---------------------------\n         Rules:            \n"
			"---------------------------\ndump: %d\nnumber_cursors: %d\n"
	"much_players: %d\n"
	"last_alive: %d\nnumber_cycle: %d\nnumber_live_of_ctd: %d\n"
	"cycles_to_die(ctd): %d\nnumber_check: %d\n"
	"---------------------------\n",
	rules->dump, rules->number_cursors,
	rules->much_players, rules->last_alive,
	rules->number_cycle, rules->num_live_of_ctd, rules->ctd,
	rules->number_check);
}

void	print_bytes_hex(unsigned char *bytes, int size)
{
	int count;

	count = 0;
	while (count < size)
	{
		ft_printf("%.2x", bytes[count]);
		count++;
		ft_printf("%.2x", bytes[count]);
		if (((count + 1) % 32) == 0)
			ft_printf("\n");
		else
			ft_printf(" ");
		count++;
	}
	ft_printf("\n");
}
