/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:01:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/30 18:36:09 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/* old func ->
static char		label_correct(char *l)
{
	while (*l && *l != LABEL_CHAR && ft_strchr(LABEL_CHARS, *l))
		l++;
	if (*l != LABEL_CHAR && *l)
		return (0);
	return (1);
}
*/

char			label_correct(char *l)
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
	while (l[*p] && l[*p] != LABEL_CHAR && l[*p] != DIRECT_CHAR &&
		l[*p] != ' ' &&  l[*p] != '\t' && l[*p] != SEPARATOR_CHAR && l[*p] != COMMENT_CHAR)
		(*p)++;
	if (l[*p] == LABEL_CHAR)
		return (1);
	if (l[*p] == DIRECT_CHAR || l[*p] == ' ' || l[*p] == '\t')
		return (2);
	if (l[*p] == SEPARATOR_CHAR)
		return (3);
	return (0);
}

/* 1- метка 2- команда 3- аргумент 0- конец строки или коммент */

static int is_number(char *s)
{
	if (*s == '-' || ft_isdigit(*s))
	{
		if (ft_is_ok(s + 1, ft_isdigit))
			return (1);
		return (0);
	}
	return (0);
}

static char		check_arg(char **arg, char *type, int *value)
{
	char	*new;
	char	*tmp;

	new = ft_strtrim(*arg);
	free(*arg);
	if (*new == DIRECT_CHAR && (*type = T_DIR))
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
		*type = T_REG;
	}
	else
		*type = T_IND;
	if (*new == LABEL_CHAR)
	{
		tmp = ft_strdup(new + 1);
		free(new);
		new = tmp;
		if (!label_correct(new) && (g_error.id = 11))
		{
			free(new);
			return (1);
		}
	}
	else
	{
		*value = ft_atoi(new);
		// tmp = ft_itoa(ft_atoi(new));
		if (!is_number(new) && (g_error.id = 11))
		{
			g_error.str_er = new;
			// free(tmp);
			free(new);
			return (1);
		}
		// free(tmp);
		new = NULL;
	}
	*arg = new;
	return (0);
}

void			check_for_comment(char *line)
{
	char	*p1;
	char	*p2;

	p1 = ft_strchr(line, COMMENT_CHAR);
	p2 = ft_strchr(line, ALT_COMMENT_CHAR);
	if (!p1 && !p2)
		return ;
	if ((p1 > p2 && p2) || !p1)
		*p2 = '\0';
	else if ((p2 > p1 && p1) || !p2)
		*p1 = '\0';
}

char			parse_args(char *line, t_tokens *new)
{
	char	**args;
	int		n_arg;

	check_for_comment(line);
	n_arg = 0;
	args = ft_strsplit(line, SEPARATOR_CHAR);
	while (args[n_arg])
	{
		if (check_arg(&args[n_arg], &new->types[n_arg], &new->values[n_arg]))
			return (1);
		n_arg++;
		if (n_arg > 3 && (g_error.id = 13))
			return (1);
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
	if (!(feedback = find_sep(line, &pos)))
		return (NULL);
	if ((feedback == 3) && (g_error.id = 10))
		return (NULL);
	if (feedback == 1)
	{
		new->mark = ft_strsub(line, 0, pos);
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
		if (g_error.id && (g_error.str_er = line))
		{
			say_error();
			free(line);
			return (NULL);
		}
		free(line);
	}
	curr->next = NULL;
	return (toks);
}
