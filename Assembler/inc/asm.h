/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:41:30 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/26 23:14:31 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <stdio.h>

typedef struct	s_out {
	char		head[4];
	char		name[PROG_NAME_LENGTH];
	char		name_null[4];
	char		code_size[4];
	char		comm[COMMENT_LENGTH];
	char		com_null[4];
	char		code[CHAMP_MAX_SIZE];
	char		c_exist;
	char		n_exist;
}				t_out;

/* validation part */

typedef struct	s_error
{
	char		*filename;
	int			id;
	char		*str_er;
}				t_error;

extern t_error			g_error;

/* types[0/1/2] тип аргумента который соответствует его коду */
typedef struct	s_t
{
	struct s_t	*next;
	char		*mark;
	t_op		*command;
	char		types[3];
	int			values[3];
	char		*a1;
	char		*a2;
	char		*a3;
}				t_tokens;

typedef	struct	s_m
{
	struct s_m	*next;
	char		*mark;
	size_t		size;
}				t_mark;



void			say_error(void);

void			read_code(int fd, t_out *out);
t_tokens		*validate(int fd);
void			cook_raw(int fd, t_out **out); // вернет код ошибки в случае провала и 0 при успешном декодировании

int				empty(char *s, size_t n);
void			skip_emptyness(char **p);
t_op			*check_command(char *l, size_t pos);

#endif
