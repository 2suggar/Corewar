/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:51:12 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/29 20:36:34 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		empty(char *s, size_t n)
{
	while (n > 0)
	{
		if (*s != '\t' && *s != ' ')
			return (0);
		s++;
		n--;
	}
	return (1);
}

void	skip_emptyness(char **p)
{
	while (**p == ' ' || **p == '\t')
	{
		(*p)++;
	}
}

void	del_marks(t_mark *me)
{
	t_mark	*tmp;

	while (me)
	{
		tmp = me;
		me = me->next;
		free(tmp->mark);
		free(tmp);
	}
}

void	del_output(t_out **out)
{
	free(*out);
	*out = NULL;
}

void	del_tokens(t_tokens *me)
{
	t_tokens	*tmp;

	while (me)
	{
		tmp = me;
		me = me->next;
		free(tmp);
	}
}
