/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/26 15:00:36 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	show_tokens(t_tokens *me)
{
	while (me)
	{
		if (me->mark)
			printf("\033[34mMARK:\033[32m|%s|\033[0m \n", me->mark);
		if (me->command)
		{
			printf("COM: \033[32m|%s|\033[0m ARG1/TYPE/VALUE: \033[32m|%s|%d|%d|\033[0m ", (char*)me->command->cmd, me->a1, (int)me->types[0], me->values[0]);
			printf("ARG2/TYPE/VALUE: \033[32m|%s|%d|%d|\033[0m ", me->a2, (int)me->types[1], me->values[1]);
			printf("ARG3/TYPE/VALUE: \033[32m|%s|%d|%d|\033[0m ", me->a3, (int)me->types[2], me->values[2]);
			printf("\n");
		}
		me = me->next;
	}
}

void read_code(int fd, t_out *out)
{
	t_tokens	*read;

	read = validate(fd);
	show_tokens(read);
	out->c_exist = 1;
}
