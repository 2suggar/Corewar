/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:24:55 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/07 20:32:28 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*itoa_oct(unsigned long long int i)
{
	char				*str;
	unsigned long long	tmp;
	unsigned long long	ost;

	str = ft_strnew(1);
	ost = i;
	while (ost > 7)
	{
		tmp = ost;
		ost = tmp / 8;
		i = tmp - (ost * 8);
		str = char_add(str, i % 10 + '0', 1);
	}
	str = char_add(str, ost % 10 + '0', 1);
	return (str);
}

long double				ft_pow(long long x, int y)
{
	long double z;
	int			f;

	f = 0;
	if (y == 0)
		return (1);
	else if (y < 0)
	{
		y = -y;
		f = 1;
	}
	z = x;
	while (--y)
	{
		z = z * x;
	}
	if (f == 1)
		return (1 / z);
	return (z);
}

char					*ft_itoa_double(long double i, int prec)
{
	char				*str;
	t_flag_f			f[7];
	int					j;
	unsigned char		*tmp;
	unsigned char		chtmp;

	tmp = (unsigned char*)&i + 9;
	chtmp = *tmp;
	j = 7;
	while (j--)
		f[j] = 0;
	if ((chtmp >> 7) == 1)
	{
		f[neg] = 1;
		i = -i;
	}
	if (prec == -1)
		prec = 6;
	str = d_to_s(i, f, prec);
	return (str);
}

char					*ft_strjoin_clean(char *s1, char *s2)
{
	size_t				i;
	char				*a;
	size_t				j;

	i = 0;
	j = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(a = (char*)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != 0)
		a[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		a[j++] = s2[i++];
	a[j] = '\0';
	free(s1);
	free(s2);
	return (a);
}
