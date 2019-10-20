/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/20 12:20:46 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_mark		*fill_mark(t_tokens *read)
{
	size_t	n;
	t_mark	*mark;
	t_mark	*start;

	n = 0;
	mark = NULL;
	while (read)
	{
		n += weight(read);
		if (read->mark && label_correct(read->mark))
		{
			start = ft_memalloc(sizeof(t_mark));
			start->next = mark;
			start->mark = read->mark;
			read->mark = NULL;
			start->size = n;
			mark = start;
		}
		else if (read->mark && (g_error.id = 15) &&
			(g_error.str_er = read->mark))
			return (NULL);
		read = read->next;
	}
	return (start);
}

static int			calc_mark(char *name, size_t n, t_mark *marks)
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
		g_error.id = 14;
		g_error.str_er = ft_strdup(name);
	}
	return (pos - (int)n);
}

static size_t			replace_marks(t_tokens *read, t_mark *mark)
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
			ft_strdel(&read->a1);
			ft_strdel(&read->a2);
			ft_strdel(&read->a3);
		}
		read = read->next;
	}
	del_marks(mark);
	return (n);
}

int					read_code(int fd, t_out *out)
{
	t_tokens	*read;
	t_mark		*mark;

	if (!(read = validate(fd)))
		return (1);
	if (!(mark = fill_mark(read)))
	{
		del_marks(mark);
		del_tokens(read);
		return (1);
	}
	// show_marks(mark);
	read = del_empty(read);
	out->code_size_int = replace_marks(read, mark);
	// show_tokens(read);
    code_to_bytes(read, out);
	out->c_exist = 1;
	del_tokens(read);
	return (0);
}
