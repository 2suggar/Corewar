/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:59:53 by aleksey           #+#    #+#             */
/*   Updated: 2019/10/15 19:37:34 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champion	*add_cursor_in_start(t_champion *cursors,
									t_champion *champion)
{
	if (cursors == 0)
		return (champion);
	champion->next = cursors;
	cursors = champion;
	return (cursors);
}

t_champion	*create_cursor(t_champion **champions, t_rules *rules)
{
	int			current_champion;
	int			count;
	t_champion	*cursors;

	current_champion = 0;
	cursors = 0;
	count = 0;
	while (++count <= rules->much_players)
	{
		current_champion = select_champion(champions, current_champion);
		champions[current_champion]->number_cursors = count;
		champions[current_champion]->to_string = &to_string;
		cursors = add_cursor_in_start(cursors, champions[current_champion]);
		rules->number_cursors++;
		current_champion++;
	}
	rules->cursors = cursors;
	return (cursors);
}
