/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:18:01 by dzboncak          #+#    #+#             */
/*   Updated: 2019/09/23 18:39:52 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H

# define COMMANDS_H
# define OP_CODE_SIZE 8
# define OP_CODE_OFFSET 2

# define LIVE_OP 0x01
# define LOAD_OP 0x02
# define STORE_OP 0x03
# define ADD_OP 0x04
# define SUB_OP 0x05
# define AND_OP 0x06
# define OR_OP 0x07
# define XOR_OP 0x08
# define ZJMP_OP 0x09
# define LOADINDEX_OP 0x0a
# define STOREINDEX_OP 0x0b
# define FORK_OP 0x0c
# define LLOAD_OP 0x0d
# define LLOADINDEX_OP 0x0e
# define LFROK_OP 0x0f
# define AFF_OP 0x10

# define PRINTING_DUMP	1
# define GAME_OVER		2

# define ERR_NUM 10
# define MAX_ERR_LENGTH 100

# define PRINT_USAGE 1
# define ERR_PARSE 2
# define ERR_TOO_MANY 3
# define ERR_N_MISUSE 4
# define ERR_DUMP 5
# define ERR_OPEN_FILE 6
# define ERR_INDEX_CUR_CHAMP 7
# define ERR_MAGIC_HEADER 8
# define ERR_CONTENT_CHAMP 9
# define ERR_SIZE_BODY 10

# include "corewar.h"

typedef struct		s_op
{
	char			*name;
	unsigned char	number_arg;
	unsigned char	types_args[3];
	unsigned char	number;
	int				cycle_before_run;
	char			*description;
	unsigned char	is_code_type_arg;
	unsigned char	dir_size;
}					t_op;

extern t_op			g_op_tab[17];
extern t_op_func	g_func_tab[17];
extern char			g_names_tab[MAX_PLAYERS + 1][PROG_NAME_LENGTH + 4];
extern const char	g_error_tab[ERR_NUM + 1][MAX_ERR_LENGTH + 1];

/*
** Args checking
*/

int					check_for_possible_args(int op_code, int args_code);
void				print_bits(const size_t size, const void *ptr);
int					get_value_from_battlefield(t_rules *rules,
						int position, int size);
void				set_value_in_battlefield(t_rules *rules, int position,
							int size, const void *value);

/*
** ASM functions
*/

void				live_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				load_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				store_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				add_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				sub_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				and_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				or_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				xor_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				zjmp_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				ldi_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				sti_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				fork_func(t_rules *rules, t_champion *crs,
							unsigned char *t_args);
void				lld_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				lldi_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				lfork_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);
void				aff_func(t_rules *rules, t_champion *cursor,
							unsigned char *t_args);

#endif
