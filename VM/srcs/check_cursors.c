/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:24:25 by aleksey           #+#    #+#             */
/*   Updated: 2019/10/15 19:21:36 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion	*delete_cursor(t_champion *del_cursor, t_champion **cursors,
		t_champion *prev, t_rules *rules)
{
	t_champion *tmp;

	rules->number_cursors--;
	tmp = del_cursor->next;
	if (del_cursor == *cursors)
		*cursors = del_cursor->next;
	else
		prev->next = del_cursor->next;
	ft_memdel((void**)&del_cursor);
	return (tmp);
}

void		check_cursors(t_champion **cursors, t_rules *rules)
{
	t_champion *cursor;
	t_champion *prev;

	cursor = *cursors;
	prev = cursor;
	rules->number_check++;
	while (cursor)
	{
		if (rules->ctd <= 0 ||
		rules->number_cycle - cursor->last_live_in_cycle >= rules->ctd)
			cursor = delete_cursor(cursor, cursors, prev, rules);
		else
		{
			prev = cursor;
			cursor = cursor->next;
		}
	}
	if (rules->num_live_of_ctd >= NBR_LIVE || MAX_CHECKS == rules->number_check)
	{
		rules->ctd -= CYCLE_DELTA;
		rules->number_check = 0;
	}
	rules->num_live_of_ctd = 0;
	rules->cursors = *cursors;
}
