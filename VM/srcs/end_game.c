/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:17:09 by bkiehn            #+#    #+#             */
/*   Updated: 2019/11/16 19:23:30 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

void	clean_memory(t_champion *cursors)
{
	t_champion *current;
	t_champion *next;

	current = cursors;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	end_game(int reason, t_rules *rules, t_champion *cursors)
{
	if (reason == PRINTING_DUMP)
	{
		print_dump(rules);
		clean_memory(cursors);
	}
	else if (reason == GAME_OVER)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n", rules->last_alive,
				g_names_tab[rules->last_alive]);
	}
	exit(0);
}
