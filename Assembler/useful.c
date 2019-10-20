/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:40:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/20 13:45:38 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			show_tokens(t_tokens *me)
{
	while (me)
	{
		if (me->mark)
			printf("\033[34mMARK:\033[32m|%s|\033[0m \n", me->mark);
		if (me->command)
		{
			printf("COM: \033[32m|%6s|\033[0m 1TYPE/VALUE: \033[32m|%d|%3d|\033[0m", (char*)me->command->cmd, (int)me->types[0], me->values[0]);
			printf("2TYPE/VALUE: \033[32m|%d|%3d|\033[0m ", (int)me->types[1], me->values[1]);
			printf("3TYPE/VALUE: \033[32m|%d|%3d|\033[0m ", (int)me->types[2], me->values[2]);
			printf("\n");
		}
		else
			printf("\033[31mI AM EMPTY\n\033[0m");
		me = me->next;
	}
}

void			show_marks(t_mark *mark)
{
	while (mark)
	{
		printf("|||%s|||%lu|||\n", mark->mark, mark->size);
		mark = mark->next;
	}
}

static size_t	weight_arg(char type, char dir_size)
{
	size_t	n;

	n = 0;
	if (type == T_DIR)
		n += dir_size;
	else if (type == T_IND)
		n += 2;
	else
		n += type;
	return (n);
}

size_t			weight(t_tokens *me)
{
	size_t	n;

	n = 0;
	if (!me->command)
		return (0);
	n += 1;
	if (me->command->a_typecode)
		n += 1;
	n += weight_arg(me->types[0], me->command->dir_size);
	n += weight_arg(me->types[1], me->command->dir_size);
	n += weight_arg(me->types[2], me->command->dir_size);
	return (n);
}

char			del_2mas(char **me, char back)
{
	while (*me)
	{
		free(*me);
		me++;
	}
	free(me);
	return (back);
}
