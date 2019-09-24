/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:27:58 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/24 20:16:59 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void read_code(int fd, t_out *out)
{
	t_tokens	*read;

	read = validate(fd);
	while (read)
	{
		printf("%s|||%s\n", (char*)read->command->cmd, read->a1);
		read = read->next;
	}
	out->c_exist = 1;
}
