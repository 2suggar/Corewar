/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/18 13:45:42 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void write_magic(t_out *out)
{
    char    *lol;
    int     value;
    int     i;

    i = 4;
    value = COREWAR_EXEC_MAGIC;
    lol = (char*)&value;
    while (--i >= 0)
        out->head[i] = *(lol + i);
}

static void read_name(int fd, t_out *out)
{
    char    *line;
    char    *start;

	if (ft_strncmp(NAME_CMD_STRING, line, ft_strlen(NAME_CMD_STRING)))
    {

        start = ft_strchr(line, '"');
        ft_strncpy(out->name, start + 1, ft_strchr(start + 1, '"') - start - 1);
    }
}

static void read_comment(int fd, t_out *out)
{
    char    *line;
    char    *start;
    char    *end;

	start = ft_strchr(line, '"');
	if ((end = ft_strchr(start + 1, '"')))
		ft_strncpy(out->comm, start + 1, end - start - 1);
	else
	{
		ft_strcat(out->comm, start);
       	while (get_next_line(fd, start) && !(end = ft_strchr(start, '"')))
       	{
			ft_strcat(out->comm, start);
			free(start);
       	}
		ft_strncat(out->comm, start, end - start - 1);
	}
}

static void	read_n_c(int fd, t_out *out)
{
	int		i;
	char	*line;

	i = 2;
	while (i--)
	{
		get_next_line(fd, &line);
		while (!*line || *line == COMMENT_CHAR)
		{
			free(line);
			get_next_line(fd, &line);
		}
		if (ft_strncmp(COMMENT_CMD_STRING, line, ft_strlen(COMMENT_CMD_STRING)))
			read_comment(fd, out);
		else if (ft_strncmp(NAME_CMD_STRING, line, ft_strlen(NAME_CMD_STRING)))
			read_name(fd, out);
	}
}	

void    cook_raw(int fd, int new)
{
    t_out	*out;

	if (!(out = ft_memalloc(sizeof(t_out))))
		return ;
	ft_bzero(out, sizeof(t_out));
	write_magic(out);
	read_n_c(fd, out);
    // read_code();
}
