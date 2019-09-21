/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:01:07 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/21 17:59:33 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_tokens	*check_line(char *line)
{
	t_tokens	*new;

	skip_emptyness(&line);
	if (*line == COMMENT_CHAR)
		return (NULL);
	new = ft_memalloc(sizeof(t_tokens));
	ft_bzero(new, sizeof(t_tokens));
	find_sep(line);
	while (*line && *line != LABEL_CHAR || *line != DIRECT_CHAR || *line != ' ')
	{
		
	}
}

t_tokens	*validate(int fd)
{
    char		*line;
    t_tokens	*toks;
	t_tokens	*curr;

    while (get_next_line(fd, &line))
    {
		if ((curr->next = check_line(line)))
			curr = curr->next;
		
	}
}