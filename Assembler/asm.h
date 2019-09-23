/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:41:30 by lcutjack          #+#    #+#             */
/*   Updated: 2019/09/23 20:30:26 by lcutjack         ###   ########.fr       */
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
	char		error;
	char		c_exist;
	char		n_exist;
}				t_out;

typedef struct	s_code
{
	struct s_code	*next;
	char			**marks;
	t_op			*command;
	char			**args;
	int				position;
}				t_code;

/* validation part */

/* t1/2/3 тип аргумента который соответствует его весу */
typedef struct	s_t
{
	struct s_t	*next;
	char		*mark;
	/*char		com[7];*/
	t_op		*command;
	/*char		n_args;*/
	char		*a1;
	char		t1;
	char		*a2;
	char		t2;
	char		*a3;
	char		t3;
}				t_tokens;


void			say_error(char *fname, char id);

void			read_code(int fd, t_out *out);
t_tokens		*validate(int fd);
char			cook_raw(int fd, t_out **out); // вернет код ошибки в случае провала и 0 при успешном декодировании

int				empty(char *s, size_t n);
void			skip_emptyness(char **p);
t_op			*check_command(char *l, size_t pos);

#endif
