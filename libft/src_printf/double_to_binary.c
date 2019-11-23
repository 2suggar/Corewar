/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:16:37 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/06 21:37:06 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					chek_mantisa(unsigned long long lon)
{
	int minus;

	minus = 1;
	if ((lon >> 63) == 1)
		minus = -1;
	lon = lon << 12;
	if ((lon >> 12) == 0)
		return (minus);
	return (0);
}

char				*chek_special_number(double i)
{
	unsigned long long	*tmp;
	unsigned long long	lon;
	unsigned long long	lontmp;
	char				*str;
	int					mantisa;

	str = NULL;
	tmp = (unsigned long long*)&i;
	lon = *tmp;
	lontmp = lon;
	lon = lon << 1;
	if ((lon >> 53) != 2047)
		return (0);
	else
		mantisa = chek_mantisa(lontmp);
	if (mantisa == 0)
		str = ft_strdup("nan");
	else if (mantisa == 1)
		str = ft_strdup("inf");
	else if (mantisa == -1)
		str = ft_strdup("-inf");
	return (str);
}
