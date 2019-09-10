/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/10 14:39:16 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static t_op *command_type(char *name)
// {
// }

static read_command(int fd)
{
	char *line;
	line = NULL;
	get_next_line(fd, &line);
}

void read_code(int fd, t_out *out)
{
	//char	*com;
	t_code	*list;

	list = NULL;
	//com = read_command(fd);
	//add_to_list(com, list);
	out->error = 0;
}
