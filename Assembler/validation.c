/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:01:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/22 15:33:17 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		label_correct(char *l)
{
	while (*l && ft_strchr(LABEL_CHARS, *l))
		l++;
	if (*l)
		return (1);
	return (0);
}

static char		find_sep(char *l, size_t *p)
{
	*p = 0;
	while(l[*p] && l[*p] != LABEL_CHAR && l[*p] != DIRECT_CHAR &&
		l[*p] != ' ' && l[*p] != SEPARATOR_CHAR && l[*p] != COMMENT_CHAR)
		(*p)++;
	if (l[*p] == LABEL_CHAR)
	{
		l[*p] = '\0';
		if (label_correct(l))
			return (1);
		return (0);
	}
	if (l[*p] == DIRECT_CHAR || l[*p] == ' ')
		return (2);
	if (l[*p] == SEPARATOR_CHAR)
		return (3);
	return (0);
}

t_op		*check_command(char *l, size_t pos)
{
	t_op	cms;

	cms = g_op_tab[1];
	// while (cms->cmd)
	// {
	// 	printf("%s", cms->cmd);
	// 	cms++;
	// }
}

static t_tokens	*check_line(char *line)
{
	t_tokens	*new;
	size_t		pos;
	char		feedback;

	skip_emptyness(&line);
	if (*line == COMMENT_CHAR)
		return (NULL);
	new = ft_memalloc(sizeof(t_tokens));
	ft_bzero(new, sizeof(t_tokens));
	feedback = find_sep(line, &pos);
	if (feedback == 1)
	{
		new->mark = line;
		line += pos + 1;
	}
	else if (feedback == 2)
	{
		new->command = check_command(line, pos);
	}
	return (NULL);
}

t_tokens	*validate(int fd)
{
    char		*line;
    /* t_tokens	*toks; */
	t_tokens	*curr;

    while (get_next_line(fd, &line))
    {
		if ((curr->next = check_line(line)))
			curr = curr->next;
		
	}
	return (NULL);
}
