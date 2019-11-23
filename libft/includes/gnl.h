/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:20:04 by lcutjack          #+#    #+#             */
/*   Updated: 2019/11/23 19:06:48 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# define BUFF_SIZE 100
# define AMOUNT_FD 4

int					get_next_line(const int fd, char **line);

#endif
