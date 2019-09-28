/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/28 20:45:02 by lcutjack         ###   ########.fr       */
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

static size_t	weight(t_tokens *me)
{
	size_t	n;

	n = 0;
	if (me->command)
		n += 1;
	if (me->command && me->command->a_typecode)
		n += 1;
	n += me->types[0] == T_DIR ? me->command->dir_size : me->types[0];
	n += me->types[1] == T_DIR ? me->command->dir_size : me->types[1];
	n += me->types[2] == T_DIR ? me->command->dir_size : me->types[2];
	return (n);
}

static t_mark *fill_mark(t_tokens *read)
{
	size_t	n;
	t_mark	*mark;
	t_mark	*start;

	n = 0;
	mark = NULL;
	while (read)
	{
		if (read->mark)
		{
			start = ft_memalloc(sizeof(t_mark));
			start->next = mark;
			start->mark = read->mark;
			read->mark = NULL;
			start->size = n;
			mark = start;
		}
		n += weight(read);
		read = read->next;
	}
	return (start);
}

static int	calc_mark(char *name, size_t n, t_mark *marks)
{
	int	pos;

	pos = 0;
	while (marks)
	{
		if (!ft_strcmp(marks->mark, name))
		{
			pos = marks->size;
			break ;
		}
		marks = marks->next;
	}
	if (!marks)
	{
		g_error.id = 15;
		g_error.str_er = name;
	}
	return (pos - (int)n);
}

static void replace_marks(t_tokens *read, t_mark *mark)
{
	size_t	n;

	n = 0;
	while (read)
	{
		if (!read->a1 && !read->a2 && !read->a3)
			n += weight(read);
		else
		{
			if (read->a1)
				read->values[0] = calc_mark(read->a1, n, mark);
			if (read->a2)
				read->values[1] = calc_mark(read->a2, n, mark);
			if (read->a3)
				read->values[2] = calc_mark(read->a3, n, mark);	
			n += weight(read);
		}
		read = read->next;
	}
}

static t_tokens *delete_empty(t_tokens *read)
{
	t_tokens	*tmp;
	t_tokens	*new;

	new = read;
	while (read->next)
	{
		if (!read->next->command)
		{
			tmp = read->next;
			read->next = read->next->next;
			free(tmp);
		}
		read = read->next;
	}
	if (!new->command)
	{
		tmp = new->next;
		free(new);
		return (tmp);
	}
	return (read);
}

void		read_code(int fd, t_out *out)
{
	t_tokens	*read;
	t_mark		*mark;

	read = validate(fd);
	mark = fill_mark(read);
	// while (mark)
	// {
	// 	printf("|||%s|||%lu|||\n", mark->mark, mark->size);
	// 	mark = mark->next; 
	// }
	read = delete_empty(read);
	replace_marks(read, mark);
	show_tokens(read);
	out->c_exist = 1;
}
