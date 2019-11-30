/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_com_nam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:46:13 by lcutjack          #+#    #+#             */
/*   Updated: 2019/11/30 16:23:07 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*give_full_name(int fd, size_t max_length, char *start, char *tmp)
{
	char	*end;
	char	*str;
	char	*tmp2;

	if ((end = ft_strchr(start, '"')))
		str = ft_strsub(start, 0, end - start);
	else
	{
		str = ft_strdup(start);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
		{
			tmp = str;
			str = ft_strjoin(str, start);
			del_3_str(&start, &tmp, NULL);
		}
		tmp = ft_strsub(start, 0, end - start);
		tmp2 = str;
		str = ft_strjoin(str, tmp);
		del_3_str(&tmp, &tmp2, &start);
	}
	if (end && ft_strlen(str) <= max_length)
		return (str);
	ft_strdel(&str);
	g_error.id = end ? 17 : 3;
	return (NULL);
}

static void	read_name(int fd, t_out *out, char *line)
{
	char	*start;
	char	*name;
	char	*tmp;

	tmp = NULL;
	if ((!(start = ft_strchr(line, '"')) || !empty(line, start - line))
		&& (g_error.id = 3))
		return ;
	if ((name = give_full_name(fd, PROG_NAME_LENGTH, start + 1, tmp)))
	{
		ft_strcpy(out->name, name);
		ft_strdel(&name);
	}
	out->n_exist = 1;
}

static void	read_comment(int fd, t_out *out, char *line)
{
	char	*start;
	char	*name;
	char	*tmp;

	tmp = NULL;
	if ((!(start = ft_strchr(line, '"')) || !empty(line, start - line))
		&& (g_error.id = 4))
		return ;
	if ((name = give_full_name(fd, COMMENT_LENGTH, start + 1, tmp)))
	{
		ft_strcpy(out->comm, name);
		ft_strdel(&name);
	}
	else
		g_error.id += 1;
	out->c_exist = 1;
}

static void	calc_len(size_t *n_len, size_t *c_len)
{
	*n_len = ft_strlen(NAME_CMD_STRING);
	*c_len = ft_strlen(COMMENT_CMD_STRING);
}

void		read_n_c(int fd, t_out *out)
{
	char	*line;
	size_t	n_len;
	size_t	c_len;

	calc_len(&n_len, &c_len);
	while (!out->c_exist || !out->n_exist)
	{
		while (get_next_line(fd, &line) && (!*line || *line == COMMENT_CHAR))
			ft_memdel((void**)&line);
		if (line && !ft_strncmp(COMMENT_CMD_STRING, line, c_len))
		{
			if (out->c_exist && (g_error.id = 6) && del_str(&line))
				return ;
			read_comment(fd, out, line + c_len);
		}
		else if (line && !ft_strncmp(NAME_CMD_STRING, line, n_len))
		{
			if (out->n_exist && (g_error.id = 5) && del_str(&line))
				return ;
			read_name(fd, out, line + n_len);
		}
		else if ((g_error.id = out->c_exist ? 7 : 8) && del_str(&line))
			return ;
		ft_memdel((void**)&line);
	}
}
