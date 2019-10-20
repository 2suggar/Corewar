/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:26:05 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/20 12:31:03 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
