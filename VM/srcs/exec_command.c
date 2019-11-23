/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:03:54 by dzboncak          #+#    #+#             */
/*   Updated: 2019/10/15 20:09:55 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

int		count_size_args(unsigned char *type_args, int how_many_arg, int op_code)
{
	int		cur_arg;
	int		num_bytes;

	num_bytes = 0;
	cur_arg = 0;
	while (cur_arg < how_many_arg)
	{
		if (type_args[cur_arg] == REG_CODE)
			num_bytes += REG_CODE_SIZE;
		else if (type_args[cur_arg] == DIR_CODE)
			num_bytes += g_op_tab[op_code].dir_size;
		else if (type_args[cur_arg] == IND_CODE)
			num_bytes += IND_SIZE;
		cur_arg++;
	}
	return (num_bytes);
}

int		check_arg_reg(t_rules *rules, t_champion *cursor,
		unsigned char *type_args)
{
	int				cur_arg;
	int				offset;
	unsigned char	arg_reg;

	cur_arg = 0;
	while (cur_arg < g_op_tab[cursor->code_operation].number_arg)
	{
		if (type_args[cur_arg] == REG_CODE)
		{
			offset = count_size_args(type_args, cur_arg,
				cursor->code_operation) + BYTES_BEFORE_ARGS;
			arg_reg = (unsigned char)get_value_from_battlefield(rules,
			cursor->position + offset, sizeof(unsigned char));
			if (arg_reg < 1 || arg_reg > REG_NUMBER)
				return (0);
		}
		cur_arg++;
	}
	return (1);
}

int		is_valid_op(t_rules *rules, t_champion *cursor,
		unsigned char *type_args)
{
	unsigned char	args_code;
	int				status_check;

	if (g_op_tab[cursor->code_operation].is_code_type_arg == 0)
		return (1);
	else
	{
		args_code = (unsigned char)get_value_from_battlefield(rules,
		cursor->position + OP_SIZE, sizeof(unsigned char));
		status_check = allowed_args(cursor->code_operation,
			args_code, type_args);
		if (status_check)
			status_check = check_arg_reg(rules, cursor, type_args);
		cursor->bytes_for_next_operation = count_size_args(type_args,
				g_op_tab[cursor->code_operation].number_arg,
				cursor->code_operation)
				+ BYTES_BEFORE_ARGS;
	}
	return (status_check);
}

void	skip_operation(t_champion *cursor)
{
	if (g_op_tab[cursor->code_operation].is_code_type_arg)
		cursor->position = (cursor->position + cursor->bytes_for_next_operation)
				% MEM_SIZE;
	else if (cursor->code_operation != ZJMP_OP ||
	(cursor->code_operation == ZJMP_OP && cursor->carry != 1))
		cursor->position = (cursor->position +
				g_op_tab[cursor->code_operation].dir_size + OP_SIZE)
				% MEM_SIZE;
}

void	exec_command(t_rules *rules, t_champion *cursor)
{
	unsigned char	*type_args;

	type_args = (unsigned char*)malloc(sizeof(unsigned char) *
				g_op_tab[cursor->code_operation].number_arg);
	if (is_valid_op(rules, cursor, type_args))
	{
		g_func_tab[cursor->code_operation](rules, cursor, type_args);
	}
	free(type_args);
	skip_operation(cursor);
}
