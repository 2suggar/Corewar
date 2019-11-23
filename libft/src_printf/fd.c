/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:23:01 by bkiehn            #+#    #+#             */
/*   Updated: 2019/04/17 17:50:59 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			found_fd(va_list *ap, char **f)
{
	int		fd;
	char	*str;

	*f = *f + 1;
	str = (char*)va_arg(*ap, char*);
	fd = open(str, O_RDWR | O_CREAT | O_APPEND);
	return (fd);
}
