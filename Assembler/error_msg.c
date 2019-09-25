/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:20:54 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/25 17:36:24 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_msg[15] = {
	"\033[0;32m; can't allocate memory\n\033[0m",
	"\033[0;32m doesn't exist or is invalid for some reasons\n\033[0m",
	"\033[0;32m have incorrect extension  [must be \".s\"]\n\033[0m",
	"\033[0;32m; champion name is not correct\n\033[0m",
	"\033[0;32m; champion comment is not correct\n\033[0m",
	"\033[0;32m; double name\n\033[0m",
	"\033[0;32m; double comment\n\033[0m",
	"\033[0;32m; no name\n\033[0m",
	"\033[0;32m; no comment\n\033[0m"
	"\033[0;32m can't be created new file\n\033[0m",
};

t_error		g_error = {NULL, 0, NULL};

void		say_error(char *fname, char id)
{
	ft_putstr_fd("The file : \033[36m", 2);
	ft_putstr_fd(fname, 2);
	ft_putstr_fd(g_msg[(int)id], 2);
}
