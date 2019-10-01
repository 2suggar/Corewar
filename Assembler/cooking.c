/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/01 16:49:07 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		cook_raw(int fd, t_out **out)
{
	t_out	*output;

	if (!(output = ft_memalloc(sizeof(t_out))))
		return ;
	read_n_c(fd, output);
	if (g_error.id)
	{
		free(output);
		say_error();
		return ;
	}
	if (read_code(fd, output))
		return ;
	write_magic(output);
	*out = output;
	del_output(out);
}
