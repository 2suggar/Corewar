/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenia <ksenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:34:26 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/04 15:20:53 by ksenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*correct_name(char *name)
{
	char *p;
	char *tmp;
	char *new;

	p = ft_strstr(name, ".s");
	if (!p || *(p + 2))
		return (NULL);
	tmp = ft_strsub(name, 0, p - name);
	new = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (new);
}

static void	say_okey(char *fname)
{
	ft_putstr_fd("\033[0;32mThe file : \033[0m", 1);
	ft_putstr_fd(g_error.filename, 1);
	ft_putstr_fd(" \033[32m ...Writing output to: \033[0m", 1);
	ft_putendl_fd(fname, 1);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*fname;
	t_out	*out;

	while (--ac)
	{
		g_error.filename = *(++av);
		g_error.id = 0;
		if ((fd = open(*av, O_RDONLY)) < 3)
			g_error.id = 1;
		else
		{
			if (!(fname = correct_name(*av)))
				g_error.id = 2;
			else
				cook_raw(fd, &out, fname);
			close(fd);
		}
		if (g_error.id)
			say_error();
		else
			say_okey(fname);
		free(fname);
	}
	return (0);
}
