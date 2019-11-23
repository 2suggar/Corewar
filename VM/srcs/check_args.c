/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:39:02 by dzboncak          #+#    #+#             */
/*   Updated: 2019/11/16 19:21:18 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "corewar.h"

int		get_num_of_players(int argc, char **argv)
{
	int	num;
	int	i;

	num = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-dump") || ft_strequ(argv[i], "-n"))
			i += 2;
		else
		{
			++num;
			++i;
		}
	}
	if (num > 4)
		error_msg(ERR_TOO_MANY);
	else if (num == 0)
		error_msg(PRINT_USAGE);
	return (num);
}

int		create_n_champ(char **argv, int argi,
		t_champion **champions, t_rules *rules)
{
	int fd;
	int current_num;

	if ((fd = open(argv[argi + 2], O_RDONLY)) == -1)
		return (0);
	++argi;
	current_num = ft_atoi(argv[argi]);
	if (current_num <= 0
	|| current_num > rules->much_players
	|| champions[current_num] != NULL)
	{
		close(fd);
		error_msg(ERR_N_MISUSE);
	}
	++argi;
	if (!create_champion(champions, fd, current_num))
	{
		ft_printf("Something wrong with %s champion!\n", argv[argi]);
		return (0);
	}
	return (1);
}

int		valid_n_flags(int argc, char **argv,
		t_champion **champions, t_rules *rules)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			if (i == argc - 1 || i == argc - 2)
				error_msg(ERR_N_MISUSE);
			if (!create_n_champ(argv, i, champions, rules))
				return (0);
			i += 2;
		}
		++i;
	}
	return (1);
}
