/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:54:34 by lcutjack          #+#    #+#             */
/*   Updated: 2019/11/23 16:10:12 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*fill_type(char *type, char *s)
{
	char	*tmp;

	if (*s == DIRECT_CHAR)
	{
		*type = T_DIR;
		tmp = ft_strdup(s + 1);
		free(s);
		return (tmp);
	}
	else if (*s == 'r' && ft_is_ok(s + 1, ft_isdigit))
	{
		*type = T_REG;
		tmp = ft_strdup(s + 1);
		free(s);
		return (tmp);
	}
	*type = T_IND;
	return (s);
}

static char		check_value(int *value, char **s)
{
	char	*tmp;

	if (**s == LABEL_CHAR)
	{
		tmp = ft_strdup(*s + 1);
		free(*s);
		*s = tmp;
		if (!label_correct(*s) && (g_error.id = 11))
			return (1);
	}
	else
	{
		*value = ft_atoi(*s);
		if (!is_number(*s) && (g_error.id = 11))
			return (1);
		free(*s);
		*s = ft_strnew(0);
	}
	return (0);
}

char			check_arg(char **arg, char *type, int *value)
{
	char	*new;

	new = ft_strtrim(*arg);
	free(*arg);
	*arg = fill_type(type, new);
	if (check_value(value, arg))
		return (1);
	return (0);
}

static void		rebase_args(t_tokens *new, int n_arg, char **args)
{
	if (args[0] && !args[0][0])
	{
		free(args[0]);
		args[0] = NULL;
	}
	if (n_arg > 1 && !args[1][0])
	{
		free(args[1]);
		args[1] = NULL;
	}
	if (n_arg > 2 && !args[2][0])
	{
		free(args[2]);
		args[2] = NULL;
	}
	new->a1 = args[0];
	new->a2 = n_arg > 1 ? args[1] : NULL;
	new->a3 = n_arg > 2 ? args[2] : NULL;
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
		if (n_arg > new->command->arg_q && (g_error.id = 12))
			return (del_2mas(args, 1));
		if (check_arg(&args[n_arg], &new->types[n_arg], &new->values[n_arg]))
			return (del_2mas(args, 1));
		n_arg++;
	}
	rebase_args(new, n_arg, args);
	free(args);
	if (n_arg != new->command->arg_q && (g_error.id = 12))
		return (1);
	if ((!(new->types[0] & new->command->arg_type[0]) ||
		(!(new->types[1] & new->command->arg_type[1]) && n_arg > 1) ||
		(!(new->types[2] & new->command->arg_type[2]) && n_arg > 2)) &&
		(g_error.id = 11))
		return (1);
	return (0);
}
