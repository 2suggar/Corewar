/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs_6_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:52:00 by bkiehn            #+#    #+#             */
/*   Updated: 2019/11/16 19:38:40 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "commands.h"

void	and_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;
	int arg2;
	int arg3;

	arg1 = get_arg(rules, cursor, t_args, 0);
	arg2 = get_arg(rules, cursor, t_args, 1);
	arg3 = get_arg(rules, cursor, t_args, 2);
	if (t_args[0] == IND_CODE)
		arg1 = get_value_from_battlefield(rules, cursor->position +
		(short)arg1 % IDX_MOD, REG_SIZE);
	else if (t_args[0] == REG_CODE)
		arg1 = cursor->reg[arg1];
	if (t_args[1] == IND_CODE)
		arg2 = get_value_from_battlefield(rules, cursor->position +
		(short)arg2 % IDX_MOD, REG_SIZE);
	else if (t_args[1] == REG_CODE)
		arg2 = cursor->reg[arg2];
	cursor->reg[arg3] = arg1 & arg2;
	cursor->carry = (cursor->reg[arg3] == 0) ? 1 : 0;
}

void	or_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;
	int arg2;
	int arg3;

	arg1 = get_arg(rules, cursor, t_args, 0);
	arg2 = get_arg(rules, cursor, t_args, 1);
	arg3 = get_arg(rules, cursor, t_args, 2);
	if (t_args[0] == IND_CODE)
		arg1 = get_value_from_battlefield(rules, cursor->position +
		(short)arg1 % IDX_MOD, REG_SIZE);
	else if (t_args[0] == REG_CODE)
		arg1 = cursor->reg[arg1];
	if (t_args[1] == IND_CODE)
		arg2 = get_value_from_battlefield(rules, cursor->position +
		(short)arg2 % IDX_MOD, REG_SIZE);
	else if (t_args[1] == REG_CODE)
		arg2 = cursor->reg[arg2];
	cursor->reg[arg3] = arg1 | arg2;
	cursor->carry = (cursor->reg[arg3] == 0) ? 1 : 0;
}

void	xor_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;
	int arg2;
	int arg3;

	arg1 = get_arg(rules, cursor, t_args, 0);
	arg2 = get_arg(rules, cursor, t_args, 1);
	arg3 = get_arg(rules, cursor, t_args, 2);
	if (t_args[0] == IND_CODE)
		arg1 = get_value_from_battlefield(rules, cursor->position +
		(short)arg1 % IDX_MOD, REG_SIZE);
	else if (t_args[0] == REG_CODE)
		arg1 = cursor->reg[arg1];
	if (t_args[1] == IND_CODE)
		arg2 = get_value_from_battlefield(rules, cursor->position +
		(short)arg2 % IDX_MOD, REG_SIZE);
	else if (t_args[1] == REG_CODE)
		arg2 = cursor->reg[arg2];
	cursor->reg[arg3] = arg1 ^ arg2;
	cursor->carry = (cursor->reg[arg3] == 0) ? 1 : 0;
}

void	zjmp_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;

	t_args[0] = DIR_CODE;
	if (cursor->carry == 1)
	{
		arg1 = (short)get_arg(rules, cursor, t_args, 0);
		if (arg1 < 0 && cursor->position < abs(arg1))
			cursor->position = (MEM_SIZE - ((-arg1 % IDX_MOD)
								- cursor->position)) % MEM_SIZE;
		else
			cursor->position = (cursor->position + (arg1 % IDX_MOD)) % MEM_SIZE;
	}
}

void	ldi_func(t_rules *rules, t_champion *cursor, unsigned char *t_args)
{
	int arg1;
	int arg2;
	int arg3;

	arg1 = get_arg(rules, cursor, t_args, 0);
	arg2 = get_arg(rules, cursor, t_args, 1);
	arg3 = get_arg(rules, cursor, t_args, 2);
	if (t_args[0] == IND_CODE)
		arg1 = get_value_from_battlefield(rules, cursor->position +
		(short)arg1 % IDX_MOD, REG_SIZE);
	else if (t_args[0] == REG_CODE)
		arg1 = cursor->reg[arg1];
	else
		arg1 = (short)arg1;
	if (t_args[1] == REG_CODE)
		arg2 = cursor->reg[arg2];
	else
		arg2 = (short)arg2;
	cursor->reg[arg3] = get_value_from_battlefield(rules, cursor->position +
	(arg1 + arg2) % IDX_MOD, REG_SIZE);
}
