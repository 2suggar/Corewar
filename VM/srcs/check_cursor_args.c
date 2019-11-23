/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursor_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:55:53 by dzboncak          #+#    #+#             */
/*   Updated: 2019/10/15 19:20:30 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

int				check_types_args_for_operation(unsigned char type_arg,
				unsigned char op_code, int arg_num)
{
	unsigned char check_status;

	if (type_arg == 0)
		return (0);
	check_status = g_op_tab[op_code].types_args[arg_num]
		<< (OP_CODE_SIZE - type_arg);
	check_status = check_status >> (OP_CODE_SIZE - 1);
	return (check_status);
}

unsigned char	get_type_arg(unsigned char args_code, int arg_num)
{
	unsigned char single_arg_code;

	single_arg_code = args_code << ((arg_num - 1) * OP_CODE_OFFSET);
	single_arg_code = single_arg_code >> ((arg_num - 1) * OP_CODE_OFFSET);
	single_arg_code = single_arg_code >> (OP_CODE_SIZE
		- (OP_CODE_OFFSET * arg_num));
	return (single_arg_code);
}

int				allowed_args(int op_code,
				unsigned char args_code, unsigned char *type_args)
{
	int	arg_num;
	int	status_check;

	status_check = 1;
	arg_num = 1;
	while (arg_num <= g_op_tab[op_code].number_arg)
	{
		type_args[arg_num - 1] = get_type_arg(args_code, arg_num);
		if (status_check &&
		!check_types_args_for_operation(type_args[arg_num - 1],
		op_code, arg_num - 1))
			status_check = 0;
		arg_num++;
	}
	return (status_check);
}
