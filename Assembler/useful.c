/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:40:53 by lcutjack          #+#    #+#             */
/*   Updated: 2019/11/23 19:21:03 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	weight_arg(char type, char dir_size)
{
	size_t	n;

	n = 0;
	if (type == T_DIR)
		n += dir_size;
	else if (type == T_IND)
		n += 2;
	else
		n += type;
	return (n);
}

size_t			weight(t_tokens *me)
{
	size_t	n;

	n = 0;
	if (!me->command)
		return (0);
	n += 1;
	if (me->command->a_typecode)
		n += 1;
	n += weight_arg(me->types[0], me->command->dir_size);
	n += weight_arg(me->types[1], me->command->dir_size);
	n += weight_arg(me->types[2], me->command->dir_size);
	return (n);
}

char			del_2mas(char **me, char back)
{
	char **start;

	start = me;
	while (*me)
	{
		free(*me);
		me++;
	}
	free(start);
	return (back);
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

char			del_str(char **line)
{
	if (!line)
		return (1);
	ft_strdel(line);
	return (1);
}
