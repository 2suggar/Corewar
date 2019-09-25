/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:01:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/25 17:34:24 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		label_correct(char *l)
{
	while (*l && ft_strchr(LABEL_CHARS, *l))
		l++;
	if (*l)
		return (0);
	return (1);
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
	if (l[*p] == DIRECT_CHAR || l[*p] == ' ' || l[*p] == '\t')
		return (2);
	if (l[*p] == SEPARATOR_CHAR)
		return (3);
	return (0);
}

/* 1- метка 2- команда 3- аргумент 0- конец строки или коммент */

static char		check_arg(char **arg, char *type)
{
	char	*new;
	char	*tmp;

	new = ft_strtrim(*arg);
	free(*arg);
	if (*new == DIRECT_CHAR && (*type = DIR_CODE))
	{
		tmp = ft_strdup(new + 1);
		free(new);
		new = tmp;
	}
	else if (*new == 'r' && ft_is_ok(new + 1, ft_isdigit))
	{
		tmp = ft_strdup(new + 1);
		free(new);
		new = tmp;
		*type = REG_CODE;
	}
	else
		*type = IND_CODE;
	if (*new == LABEL_CHAR)
	{
		tmp = ft_strdup(new + 1);
		free(new);
		new = tmp;
		if (!label_correct(new))
			return (1);
	}
	else if (ft_strcmp(ft_itoa(ft_atoi(new)), new))
		return (1);
	*arg = new;
	return (0);
}

char			parse_args(char *line, t_tokens *new)
{
	char	**args;
	int		n_arg;

	n_arg = 0;
	args = ft_strsplit(line, SEPARATOR_CHAR);
	while (args[n_arg])
	{
		if (n_arg > 3)
			return (1);
		if (check_arg(&args[n_arg], &new->types[n_arg]))
			return (1);
		n_arg++;
	}
	new->a1 = args[0];
	new->a2 = n_arg > 1 ? args[1] : NULL;
	new->a3 = n_arg > 2 ? args[2] : NULL;
	if (n_arg != new->command->arg_q)
		return (1);
	if (!(new->types[0] & new->command->arg_type[0]) ||
		(!(new->types[1] & new->command->arg_type[1]) && n_arg > 1) ||
		(!(new->types[2] & new->command->arg_type[2]) && n_arg > 2))
		return (1);
	return (0);
}

static t_tokens	*check_line(char *line)
{
	t_tokens	*new;
	size_t		pos;
	char		feedback;

	skip_emptyness(&line);
	if (*line == COMMENT_CHAR || !*line)
		return (NULL);
	new = ft_memalloc(sizeof(t_tokens));
	if (!(feedback = find_sep(line, &pos)) || feedback == 3)
		return (NULL);
	if (feedback == 1)
	{
		new->mark = line;
		line += pos + 1;
		skip_emptyness(&line);
		if ((feedback = find_sep(line, &pos)) == 0)
			return (new);
		else if (feedback != 2)
			return (NULL);
	}
	if (!(new->command = check_command(line, pos)))
		return (NULL);
	if (parse_args(line + pos + 1, new))
		return (NULL);
	return (new);
}

t_tokens	*validate(int fd)
{
    char		*line;
    t_tokens	*toks;
	t_tokens	*curr;
	t_tokens	*new;

	toks = NULL;
    while (get_next_line(fd, &line))
    {
		if ((new = check_line(line)))
		{
			if (!toks)
			{
				toks = new;
				curr = toks;
			}
			else
			{
				curr->next = new;
				curr = curr->next;
			}
		}
	}
	curr->next = NULL;
	return (toks);
}
