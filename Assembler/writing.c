/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenia <ksenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:26:05 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/03 00:55:10 by ksenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/* (new = open(fname, O_RDWR | O_CREAT, 0600)) < 3) */

void	write_magic(t_out *out)
{
	char	*lol;
	int		value;
	int		i;
	int		j;

	i = -1;
	j = 4;
	value = COREWAR_EXEC_MAGIC;
	lol = (char*)&value;
	while (++i < 4)
		out->head[--j] = *(lol + i);
}
