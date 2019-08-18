/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:34:26 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/18 14:26:06 by lcutjack         ###   ########.fr       */
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

int			main(int ac, char **av){
	int		new;
	int		fd;
	char	*fname;

	while (--ac)
	{
		if ((fd = open(*(++av), O_RDONLY)) < 3)
			say_error(*av, 0);
		else
		{
			if (!(fname = correct_name(*av)))
				say_error(*av, 1);
			else if ((new = open(fname, O_RDWR | O_CREAT, 0600)) < 3)
				say_error(*av, 2);
			else
				cook_raw(fd, new, fname);
			close(fd);
			close(new);
		}
	}
	return (0);
}