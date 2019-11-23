/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:02:24 by aleksey           #+#    #+#             */
/*   Updated: 2019/11/16 19:39:34 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

void	action_with_cursor(t_champion *cursor, t_rules *rules)
{
	if (cursor->cycle_before_run == 0)
	{
		cursor->code_operation = rules->battlefield[cursor->position];
		if (cursor->code_operation >= LIVE_OP &&
				cursor->code_operation <= AFF_OP)
			cursor->cycle_before_run = g_op_tab[cursor->code_operation].
					cycle_before_run - 1;
		else
			cursor->position = (cursor->position + 1) % MEM_SIZE;
	}
	else
	{
		cursor->cycle_before_run--;
		if (cursor->cycle_before_run == 0)
			exec_command(rules, cursor);
	}
}

void	introduction(t_champion **champions, t_rules *rules)
{
	int		current_champion;
	int		count;

	current_champion = 0;
	count = 0;
	ft_printf("Introducing contestants...\n");
	while (++count <= rules->much_players)
	{
		current_champion = select_champion(champions, current_champion);
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				champions[current_champion]->number,
				champions[current_champion]->size,
				champions[current_champion]->name,
				champions[current_champion]->comment);
		free(champions[current_champion]->comment);
		free(champions[current_champion]->body);
		current_champion++;
	}
	free(champions);
}

void	start_game(t_rules *rules, t_champion **champions)
{
	int			ctd;
	t_champion	*cursor;

	ctd = rules->ctd;
	cursor = rules->cursors;
	introduction(champions, rules);
	while (rules->number_cursors)
	{
		rules->number_cycle++;
		ctd--;
		while (cursor)
		{
			action_with_cursor(cursor, rules);
			cursor = cursor->next;
		}
		if (ctd <= 0)
		{
			check_cursors(&rules->cursors, rules);
			ctd = rules->ctd;
		}
		cursor = rules->cursors;
		if (rules->dump == rules->number_cycle)
			end_game(PRINTING_DUMP, rules, rules->cursors);
	}
	end_game(GAME_OVER, rules, rules->cursors);
}
