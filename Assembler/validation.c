/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:01:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/20 13:37:14 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		find_sep(char *l, size_t *p)
{
	*p = 0;
	while (l[*p] && l[*p] != LABEL_CHAR && l[*p] != DIRECT_CHAR && l[*p] != ' '
		&& l[*p] != '\t' && l[*p] != SEPARATOR_CHAR && l[*p] != COMMENT_CHAR)
		(*p)++;
	if (l[*p] == LABEL_CHAR)
		return (1);
	if (l[*p] == DIRECT_CHAR || l[*p] == ' ' || l[*p] == '\t')
		return (2);
	if (l[*p] == SEPARATOR_CHAR)
		return (3);
	return (0);
}

static void		*free_return(t_tokens *new)
{
	del_tokens(new);
	return (NULL);
}

static t_tokens	*check_line(char *line)
{
	t_tokens	*new;
	size_t		pos;
	char		feedback;

	skip_emptyness(&line);
	if (*line == COMMENT_CHAR || !*line)
		return (NULL);
	if (!(feedback = find_sep(line, &pos)) ||
		((feedback == 3) && (g_error.id = 10)))
		return (NULL);
	new = ft_memalloc(sizeof(t_tokens));
	new->next = NULL;
	if (feedback == 1)
	{
		new->mark = ft_strsub(line, 0, pos);
		line += pos + 1;
		skip_emptyness(&line);
		if ((feedback = find_sep(line, &pos)) == 0)
			return (new);
		else if (feedback != 2)
			return (free_return(new));
	}
	if (!(new->command = check_command(line, pos)) ||
		parse_args(line + pos + 1, new))
		return (free_return(new));
	return (new);
}

static void		add_tok(t_tokens **toks, t_tokens **curr, t_tokens *new)
{
	if (!*toks)
	{
		*toks = new;
		*curr = *toks;
	}
	else
	{
		(*curr)->next = new;
		*curr = (*curr)->next;
	}
}

t_tokens		*validate(int fd)
{
	char		*line;
	t_tokens	*toks;
	t_tokens	*curr;
	t_tokens	*new;

	toks = NULL;
	while (get_next_line(fd, &line))
	{
		if ((new = check_line(line)))
			add_tok(&toks, &curr, new);
		if (g_error.id && (g_error.str_er = line))
		{
			line = NULL;
			del_tokens(toks);
			return (NULL);
		}
		ft_strdel(&line);
	}
	curr->next = NULL;
	return (toks);
}
