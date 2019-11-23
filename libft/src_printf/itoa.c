/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:45:13 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/07 16:11:01 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			minus(long long int n, long long int *i)
{
	if (n == -9223372036854775807 - 1)
	{
		*i += 2;
		return (-(n % 1000000000000000000));
	}
	else
		*i = *i + 1;
	return (-n);
}

char					*ft_itoa_long(long long int n)
{
	char				*a;
	long long int		i;
	long long int		buf;

	i = 2;
	if (n < 0)
		n = minus(n, &i);
	buf = n;
	while ((buf = (buf / 10)) > 0)
		i++;
	if (!(a = malloc(sizeof(char) * i)))
		return (0);
	a[--i] = '\0';
	a[--i] = (n % 10) + '0';
	while ((n = (n / 10)) > 0)
		a[--i] = (n % 10) + '0';
	if (i == 2)
		a[--i] = '9';
	if (i == 1)
		a[--i] = '-';
	return (a);
}

char					*ft_itoa_unlong(unsigned long long int n)
{
	char				*a;
	unsigned long long	i;
	unsigned long long	buf;

	i = 2;
	buf = n;
	while ((buf = (buf / 10)) > 0)
		i++;
	if (!(a = malloc(sizeof(char) * i)))
		return (0);
	a[--i] = '\0';
	a[--i] = (n % 10) + '0';
	while ((n = (n / 10)) > 0)
		a[--i] = (n % 10) + '0';
	return (a);
}

int						dec_to_letter(char dec, int size)
{
	if (dec == 10 && size == 0)
		return ('a');
	else if (dec == 10)
		return ('A');
	else if (dec == 11 && size == 0)
		return ('b');
	else if (dec == 11)
		return ('B');
	else if (dec == 12 && size == 0)
		return ('c');
	else if (dec == 12)
		return ('C');
	else if (dec == 13 && size == 0)
		return ('d');
	else if (dec == 13)
		return ('D');
	else if (dec == 14 && size == 0)
		return ('e');
	else if (dec == 14)
		return ('E');
	else if (dec == 15 && size == 0)
		return ('f');
	else if (dec == 15)
		return ('F');
	return (0);
}

char					*itoa_hex(unsigned long long int i, int size)
{
	char				discharge;
	char				*str;
	unsigned long long	tmp;
	unsigned long long	ost;

	str = ft_strnew(1);
	str[1] = 0;
	ost = i;
	while (ost > 15)
	{
		tmp = ost;
		ost = tmp / 16;
		i = tmp - (ost * 16);
		if (i > 9)
			discharge = dec_to_letter(i, size);
		else
			discharge = i % 10 + '0';
		str = char_add(str, discharge, 1);
	}
	if (ost > 9)
		discharge = dec_to_letter(ost, size);
	else
		discharge = ost % 10 + '0';
	str = char_add(str, discharge, 1);
	return (str);
}
