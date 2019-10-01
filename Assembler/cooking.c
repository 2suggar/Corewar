/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/10/01 14:51:48 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	read_name(int fd, t_out *out, char *line)
{
	char	*start;
	char	*end;

	if ((!(start = ft_strchr(line, '"')) || !empty(line, start - line))
		&& (g_error.id = 3))
		return ;
	if ((end = ft_strchr(start + 1, '"')))
		ft_strncpy(out->name, start + 1, end - start - 1);
	else
	{
		ft_strcat(out->name, start + 1);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
		{
			ft_strcat(out->name, start);
			free(start);
		}
		ft_strncat(out->name, start, end - start - 1);
	}
	out->n_exist = 1;
}

static void	read_comment(int fd, t_out *out, char *line)
{
	char	*start;
	char	*end;

	if ((!(start = ft_strchr(line, '"')) || !empty(line, start - line))
		&& (g_error.id = 4))
		return ;
	if ((end = ft_strchr(start + 1, '"')))
		ft_strncpy(out->comm, start + 1, end - start - 1);
	else
	{
		ft_strcat(out->comm, start + 1);
		while (get_next_line(fd, &start) && !(end = ft_strchr(start, '"')))
		{
			ft_strcat(out->comm, start);
			free(start);
		}
		ft_strncat(out->comm, start, end - start - 1);
	}
	out->c_exist = 1;
}

static void	read_n_c(int fd, t_out *out)
{
	char	*line;
	size_t	n_len;
	size_t	c_len;

	n_len = ft_strlen(NAME_CMD_STRING);
	c_len = ft_strlen(COMMENT_CMD_STRING);
	while (!out->c_exist || !out->n_exist)
	{
		while (get_next_line(fd, &line) && (!*line || *line == COMMENT_CHAR))
			ft_memdel((void**)&line);
		if (!ft_strncmp(COMMENT_CMD_STRING, line, c_len))
		{
			if (out->c_exist && (g_error.id = 6))
				break ;
			read_comment(fd, out, line + c_len);
		}
		else if (!ft_strncmp(NAME_CMD_STRING, line, n_len))
		{
			if (out->n_exist && (g_error.id = 5))
				break ;
			read_name(fd, out, line + n_len);
		}
		ft_memdel((void**)&line);
		if (g_error.id)
			return ;
	}
}

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
