/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:20:32 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/04 12:18:11 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char		*got_the_line(char *mem, char **line)
{
	char	*tmp;
	char	*endl;

	if (!(endl = ft_strchr(mem, '\n')))
	{
		endl = mem + ft_strlen(mem);
		tmp = ft_strnew(0);
		*line = ft_strdup(mem);
	}
	else
	{
		tmp = ft_strdup(endl + 1);
		*line = ft_strsub(mem, 0, endl - mem);
	}
	ft_strdel(&mem);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*mem[AMOUNT_FD];
	int			res;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (mem[fd] == NULL)
		mem[fd] = ft_strnew(0);
	while (!ft_strchr(mem[fd], '\n') && (res = read(fd, buf, BUFF_SIZE)))
	{
		buf[res] = '\0';
		tmp = mem[fd];
		mem[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (*mem[fd] != '\0')
	{
		mem[fd] = got_the_line(mem[fd], line);
		return (1);
	}
	return (0);
}
