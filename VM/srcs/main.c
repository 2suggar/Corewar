/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:44:53 by bkiehn            #+#    #+#             */
/*   Updated: 2019/11/30 14:15:54 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "corewar.h"

void		error_msg(int err_code)
{
	ft_putendl(g_error_tab[err_code]);
	exit(err_code);
}

int			num_champ(t_champion **champions)
{
	int		current_number_champion;

	current_number_champion = 1;
	while (champions[current_number_champion] != NULL)
	{
		current_number_champion++;
	}
	return (current_number_champion);
}

void		parse_arg(int argc, char **argv, t_rules *rules,
		t_champion **champs)
{
	int arg;
	int fd;

	arg = 1;
	while (arg < argc)
	{
		if (ft_strequ(argv[arg], "-dump"))
		{
			arg++;
			if (arg < argc && ft_is_ok(argv[arg], ft_isdigit))
				rules->dump = ft_atoi(argv[arg]);
			else
				error_msg(PRINT_USAGE);
		}
		else if (ft_strequ(argv[arg], "-n"))
			arg += 2;
		else
		{
			if ((fd = open(argv[arg], O_RDONLY)) == -1)
				error_msg(ERR_OPEN_FILE);
			else
				create_champion(champs, fd, num_champ(champs));
		}
		arg++;
	}
}

void		set_rules(t_rules *rules, t_champion **champions)
{
	int	current_champion;

	current_champion = 4;
	while (champions[current_champion] == NULL)
		current_champion--;
	rules->last_alive = current_champion;
	rules->name_winner = champions[current_champion]->name;
	rules->ctd = CYCLE_TO_DIE;
}

/*
**	Исторически сложилось, что начал работать с массивом
**	чемпионов и последнии параметры для них устанавливаются в
**	creat_battlefield, но для удобства реализации процесса игры
**	чемпионов нужно переделать в список, и обозвать их курсорами
**	что делается в creat_cursor, но это всё теже структуры.
**	number_cursor определяется здесь же
**	Функции для отладки%
**	print_rules(rules);
**	print_cursors(cursors, 1);
**	print_battlefiled(rules, champions);
*/

int			main(int argc, char **argv)
{
	t_rules			rules;
	t_champion		**champions;
	t_champion		*cursors;

	champions = ft_memalloc(sizeof(t_champion*) * 5);
	ft_memset(&rules, 0, sizeof(t_rules));
	rules.much_players = get_num_of_players(argc, argv);
	if (!valid_n_flags(argc, argv, champions, &rules))
		error_msg(ERR_PARSE);
	parse_arg(argc, argv, &rules, champions);
	if (rules.much_players != 0)
		set_rules(&rules, champions);
	else
		error_msg(PRINT_USAGE);
	create_battlefield(&rules, champions);
	cursors = create_cursor(champions, &rules);
	start_game(&rules, champions);
}
