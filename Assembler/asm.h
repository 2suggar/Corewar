/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:41:30 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/18 16:18:02 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdio.h>

typedef struct	s_out {
    char	head[4];
    char	name[PROG_NAME_LENGTH];
    char	name_null[4];
    char	code_size[4];
    char	comm[COMMENT_LENGTH];
    char	com_null[4];
    char	*code;
    char    error;
    char	c_true;
    char	n_true;
}				t_out;

void    say_error(char *fname, char id);
void	cook_raw(int fd, int new, char *fname);
void    read_code(int fd, t_out *out);

int     empty(char *s, size_t n);

#endif