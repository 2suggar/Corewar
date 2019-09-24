/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:34:26 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/24 18:28:21 by lcutjack         ###   ########.fr       */
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
	char	id_error;

	while (--ac)
	{
		if ((fd = open(*(++av), O_RDONLY)) < 3)
			say_error(*av, 1);
		else
		{
			if (!(fname = correct_name(*av)))
				say_error(*av, 2);
			else if ((id_error = cook_raw(fd, &out)))
				say_error(*av, id_error);
			else
				break ;
			close(fd);
		}
	}
	return (0);
}
