/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/21 15:43:07 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static t_op *command_type(char *name)
// {
// }

// static t_code	*read_command(int fd, t_code *list)
// {
// 	char	*line;
// 	t_code	*new;
// 	char	*marks[10];

// 	line = NULL;
// 	new = ft_memalloc(sizeof(t_code));
// 	while (1)
// 	{
// 		get_next_line(fd, &line);
// 		skip_emptyness(&line);
// 		check_mark()

// 	}
// }

// void read_code(int fd, t_out *out)
// {
// 	t_code	*list;

// 	list = NULL;
// 	list = read_command(fd, list);
// 	out->error = 0;
// }

int		split_tokens(char *line)
{
	if (its_command(line))
	
}

t_code	*read_str(int fd)
{
	char	*line;
	t_code	*lst;

	while (get_next_line(fd, &line))
	{
		if (split_tokens(line))
		{
			 
		}
	}
}

void read_code(int fd, t_out *out)
{
	t_tokens	*read;

	read = validate(fd);
}
