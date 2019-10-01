/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:53:52 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/01 15:51:45 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			label_correct(char *l)
{
	while (*l && ft_strchr(LABEL_CHARS, *l))
		l++;
	if (*l)
		return (0);
	return (1);
}

int				is_number(char *s)
{
	if (*s == '-' || ft_isdigit(*s))
	{
		if (ft_is_ok(s + 1, ft_isdigit))
			return (1);
		return (0);
	}
	return (0);
}

t_tokens		*del_empty(t_tokens *read)
{
	t_tokens	*tmp;
	t_tokens	*new;

	new = read;
	while (read && read->next)
	{
		if (!(read->next->command))
		{
			tmp = read->next;
			read->next = read->next->next;
			free(tmp);
		}
		else
			read = read->next;
	}
	if (!(new->command))
	{
		tmp = new->next;
		free(new);
		return (tmp);
	}
	return (new);
}
