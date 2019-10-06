/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/06 21:51:39 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		cook_raw(int fd, t_out **out, char *filename)
{
	t_out	*output;
	char	buf[1];

	lseek(fd, -1, 2);
	read(fd, buf, 1);
	if (*buf != '\n' && (g_error.id = 16))
		return ;
	lseek(fd, 0, 0);
	if (!(output = ft_memalloc(sizeof(t_out))))
		return ;
	read_n_c(fd, output);
	if (g_error.id)
	{
		del_output(&output);
		say_error();
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
