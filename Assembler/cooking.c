/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/11/16 20:44:54 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	check_newline(int fd)
{
	char buf[1];

	lseek(fd, -1, 2);
	read(fd, buf, 1);
	if (*buf != '\n' && (g_error.id = 16))
		return (1);
	lseek(fd, 0, 0);
	return (0);
}

void		cook_raw(int fd, t_out **out, char *filename)
{
	t_out	*output;

	if (check_newline(fd))
		return ;
	if (!(output = ft_memalloc(sizeof(t_out))))
		return ;
	read_n_c(fd, output);
	if (g_error.id)
	{
		del_output(&output);
		return ;
	}
	if (read_code(fd, output))
	{
		del_output(&output);
		return ;
	}
	write_magic(output);
	to_file(output, filename);
	*out = output;
	del_output(out);
}
