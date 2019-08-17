/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:20:54 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/04 15:40:37 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char *msg[15] = {
    " doesn't exist or is invalid for some reasons\n",
    " have incorrect extension  [must be \".s\"]\n",
    " can't be created\n"
};

void say_error(char *fname, char id)
{
    ft_putstr_fd("The file : ", 2);
    ft_putstr_fd(fname, 2);
    ft_putstr_fd(msg[(int)id], 2);
}