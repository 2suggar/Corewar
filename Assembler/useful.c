/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:40:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/01 15:59:41 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		show_tokens(t_tokens *me)
{
	while (me)
	{
		if (me->mark)
			printf("\033[34mMARK:\033[32m|%s|\033[0m \n", me->mark);
		if (me->command)
		{
			printf("COM: \033[32m|%6s|\033[0m ARG1/TYPE/VALUE: \033[32m|%6s|%d|%3d|\033[0m ", (char*)me->command->cmd, me->a1, (int)me->types[0], me->values[0]);
			printf("ARG2/TYPE/VALUE: \033[32m|%6s|%d|%3d|\033[0m ", me->a2, (int)me->types[1], me->values[1]);
			printf("ARG3/TYPE/VALUE: \033[32m|%6s|%d|%3d|\033[0m ", me->a3, (int)me->types[2], me->values[2]);
			printf("\n");
		}
		else
			printf("\033[31mI AM EMPTY\n\033[0m");
		me = me->next;
	}
}

void		show_marks(t_mark *mark)
{
	while (mark)
	{
		printf("|||%s|||%lu|||\n", mark->mark, mark->size);
		mark = mark->next;
	}
}
