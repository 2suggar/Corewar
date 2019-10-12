/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:45:58 by ksenia            #+#    #+#             */
/*   Updated: 2019/10/12 02:54:09 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char				the_code(char me)
{
	if (me == T_DIR)
		return (2);
	if (me == T_REG)
		return (1);
	if (me == T_IND)
		return (3);
	return (0);
}

static unsigned char	typecode(t_tokens *tokens)
{
	unsigned char	res;
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;

	a = the_code(tokens->types[0]);
	b = the_code(tokens->types[1]);
	c = the_code(tokens->types[2]);
	res = 0 | ((a << 6) & 192) | ((b << 4) & 48) | ((c << 2) & 12);
	return (res);
}

static void				args_circle(t_tokens *tokens, t_out *out, int *i)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if (tokens->types[j] == 1)
			ft_memcpy_rev(&(out->code[(*i)++]), &(tokens->values[j]), 1);
		else if (tokens->types[j] == 2)
		{
			if (tokens->command->dir_size == 2)
				ft_memcpy_rev(&(out->code[*i]), &(tokens->values[j]), 2);
			else
			{
				ft_memcpy_rev(&(out->code[*i]), &(tokens->values[j]), 4);
				*i += 2;
			}
			*i += 2;
		}
		else if (tokens->types[j] == 4)
		{
			ft_memcpy_rev(&(out->code[*i]), &(tokens->values[j]), 2);
			*i += 2;
		}
		j++;
	}
}

void					code_to_bytes(t_tokens *tokens, t_out *out)
{
	int	i;

	i = 0;
	out->code = ft_memalloc(out->code_size_int);
	while (tokens)
	{
		out->code[i++] = tokens->command->opcode;
		if (tokens->command->a_typecode)
			out->code[i++] = typecode(tokens);
		args_circle(tokens, out, &i);
		tokens = tokens->next;
	}
	ft_memcpy_rev(out->code_size, &i, sizeof(int));
}

void					to_file(t_out	*output, char *filename)
{
	int	fd;

    if ((fd = open(filename, O_WRONLY | O_CREAT, 0600)) < 3)
		g_error.id = 10;
	write(fd, &output->head, 4);
	write(fd, &output->name, PROG_NAME_LENGTH);
	write(fd, &output->name_null, 4);
	write(fd, &output->code_size, 4);
	write(fd, &output->comm, COMMENT_LENGTH);
	write(fd, &output->com_null, 4);
	write(fd, output->code, output->code_size_int);
    close(fd);
}
