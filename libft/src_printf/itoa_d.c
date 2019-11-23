/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:24:37 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/06 23:15:19 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*d_to_s(long double i, t_flag_f *f, int prec)
{
	char	*str2;
	char	*str;
	int		lstr;

	str = ft_itoa_unlong(i);
	lstr = ft_strlen(str) - 1;
	f[lc] = str[lstr];
	if (prec != 0)
	{
		str2 = flags_f(f, i, prec);
		str2 = drob_f(str2, prec, f, i);
	}
	else
		flags_f_p0(f, i, prec);
	str = real_f(f, str, lstr);
	if (f[neg] == 1)
		str = char_add(str, '-', 1);
	if (prec != 0)
		str = ft_strjoin_clean(str, str2);
	return (str);
}

char			*real_f(t_flag_f *f, char *str, int lstr)
{
	while (f[dis] == 1)
	{
		f[dis] = 0;
		str[lstr]++;
		if (str[lstr] > '9')
		{
			str[lstr] = '0';
			f[dis] = 1;
		}
		lstr--;
		if (lstr < 0 && f[dis] == 1)
		{
			f[dis] = 0;
			str = char_add(str, '1', 1);
		}
	}
	return (str);
}

char			*flags_f(t_flag_f *f, long double i, int p)
{
	char	*str2;
	char	d;

	str2 = ft_strnew(1);
	if ((U_LL)(i * ft_pow(10, p + 2)) % 10 + '0' == '0')
		i = i + ft_pow(10, -(p + 3));
	if ((U_LL)(i * ft_pow(10, p + 2)) % 10 + '0' > '0')
		f[p2] = 1;
	if ((U_LL)(i * ft_pow(10, p + 1)) % 10 + '0' == '5')
		f[p1r] = 1;
	if ((U_LL)(i * ft_pow(10, p + 1)) % 10 + '0' > '5')
		f[p1b] = 1;
	if ((d = (U_LL)(i * ft_pow(10, p)) % 10 + '0') > '6')
		f[p0] = 1;
	if (f[p1b] == 1)
		d++;
	else if ((f[p1r] == 1 && f[p2] == 1) || (f[p0] == 1 && f[p1r] == 1))
		d++;
	if (d > '9')
	{
		d = '0';
		f[dis] = 1;
	}
	return (char_add(str2, d, 1));
}

char			*drob_f(char *str2, int prec, t_flag_f *f, long double i)
{
	char		d;

	while (--prec)
	{
		d = (U_LL)(i * ft_pow(10, prec)) % 10 + '0';
		if (f[dis] == 1)
		{
			d++;
			f[dis] = 0;
		}
		if (d > '9')
		{
			d = '0';
			f[dis] = 1;
		}
		str2 = char_add(str2, d, 1);
	}
	str2 = char_add(str2, '.', 1);
	return (str2);
}

void			flags_f_p0(t_flag_f *f, long double i, int p)
{
	char	discharge;

	discharge = f[lc];
	if ((U_LL)(i * ft_pow(10, p + 2)) % 10 + '0' == '0')
		i = i + ft_pow(10, -(p + 3));
	if ((U_LL)(i * ft_pow(10, p + 2)) % 10 + '0' > '0')
		f[p2] = 1;
	if ((U_LL)(i * ft_pow(10, p + 1)) % 10 + '0' == '5')
		f[p1r] = 1;
	if ((U_LL)(i * ft_pow(10, p + 1)) % 10 + '0' > '5')
		f[p1b] = 1;
	if (discharge > '4')
		f[p0] = 1;
	if ((f[p1b] == 1) || (f[p1r] == 1 && (discharge % 2) != 0)
	|| (f[p2] == 1 && f[p1r] == 1))
		f[dis] = 1;
}
