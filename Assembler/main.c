/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:34:26 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/25 19:07:19 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*correct_name(char *name)
{
	char *p;

	p = ft_strstr(name, ".s");
	if (!p || *(p + 2))
		return (NULL);
	return (ft_strjoin(ft_strsub(name, 0, p - name), ".cor"));
}

int			main(int ac, char **av)
{
	int		fd;
	char	*fname;
	t_out	*out;

	while (--ac)
	{
		g_error.filename = *av;
		if ((fd = open(*(++av), O_RDONLY)) < 3)
			g_error.id = 1;
		else
		{
			if (!(fname = correct_name(*av)))
				g_error.id = 2;
			else
				cook_raw(fd, &out);
			close(fd);
		}
		if (g_error.id)
			say_error();
	}
	return (0);
}
