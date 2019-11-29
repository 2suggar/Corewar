/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:20:54 by lcutjack          #+#    #+#             */
/*   Updated: 2019/11/29 19:44:57 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_msg[19] = {
	"\033[33m; can't allocate memory\n\033[0m",
	"\033[33m doesn't exist or is invalid for some reasons\n\033[0m",
	"\033[33m have incorrect extension  [must be \".s\"]\n\033[0m",
	"\033[33m; champion name is not correct\n\033[0m",
	"\033[33m; champion comment is not correct\n\033[0m",
	"\033[33m; double name\n\033[0m",
	"\033[33m; double comment\n\033[0m",
	"\033[33m; no name\n\033[0m",
	"\033[33m; no comment\n\033[0m",
	"\033[33m can't be created new file\n\033[0m",
	"\033[33m incorrect command:   \033[0m",
	"\033[33m incorrect argument:   \033[0m",
	"\033[33m incorrect number of arguments:   \033[0m",
	"\033[33m incorrect command:   \033[0m",
	"\033[33m this label doesn't exist:   \033[0m",
	"\033[33m incorrect label:   \033[0m",
	"\033[33m there is no newline at the end of the file \n\033[0m",
	"\033[33m champion name is too long \n\033[0m",
	"\033[33m champion comment is too long \n\033[0m"
};

t_error		g_error = {NULL, 0, NULL};

void		say_error(char *fname)
{
	ft_putstr_fd("\033[33mThe file : \033[0m", 2);
	ft_putstr_fd(g_error.filename, 2);
	ft_putstr_fd(g_msg[g_error.id], 2);
	if (g_error.id > 9 && g_error.id < 16)
	{
		ft_putendl_fd(g_error.str_er, 2);
	}
	g_error.id = 0;
	ft_strdel(&g_error.str_er);
	ft_strdel(&fname);
}
