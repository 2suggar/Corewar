/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:20:04 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/04 12:18:01 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# define BUFF_SIZE 20
# define AMOUNT_FD 4

typedef struct		s_files
{
	char			*content;
	int				endl;
	int				fd;
	struct s_files	*next;
}					t_files;

int					get_next_line(const int fd, char **line);

#endif
