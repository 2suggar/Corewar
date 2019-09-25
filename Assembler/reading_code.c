/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/25 14:50:02 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	show_tokens(t_tokens *me)
{
	while (me)
	{
		if (me->mark)
			printf("MARK:\033[32m|%s|\033[0m ", me->mark);
		if (me->command)
		{
			printf("COM: \033[32m|%s|\033[0m ARG1/TYPE: \033[32m|%s|%d|\033[0m ", (char*)me->command->cmd, me->a1, (int)me->types[0]);
			if (me->a2)
				printf("ARG2/TYPE: \033[32m|%s|%d|\033[0m ", me->a2, (int)me->types[1]);
			/*if (me->a3)
				printf("ARG3/TYPE: \033[32m|%s|%d|\033[0m ", me->a3, (int)me->types[2]);*/
		}
		printf("\n");
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
