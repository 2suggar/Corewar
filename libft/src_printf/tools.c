/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:19 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/07 20:23:06 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_p_buf *tmp, char *start)
{
	while (start != tmp->end_find)
	{
		if (ft_isdigit(*start))
		{
			if (*start != '0')
			{
				tmp->end_find = start;
				tmp->width = ft_atoi(start);
				return ;
			}
		}
		start++;
	}
	if (tmp->d_type == CHAR)
		tmp->width = 1;
	else
		tmp->width = -1;
}

int		find_max(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return (a);
		return (c);
	}
	else if (b >= a)
	{
		if (b >= c)
			return (b);
		return (c);
	}
	else if (c >= a)
	{
		if (c >= b)
			return (c);
		return (b);
	}
	return (a);
}

int		calc_diff_w(t_p_buf *p_str, char *prev_str, int *diff_w, int *diff_p)
{
	int		len;
	int		wid;

	len = ft_strlen(prev_str);
	set_diff_p(p_str, diff_p, &wid, &len);
	if (wid > len)
	{
		if (p_str->flag[NO_FLAG])
			return (*diff_w = wid - len);
		else if (p_str->flag[SHARP])
		{
			if (p_str->d_type == HEX || p_str->d_type == HEX_B)
				return (*diff_w = wid - len - 2);
			else if (p_str->d_type == OCT)
				return (*diff_w = wid - len - 1);
		}
	}
	return (*diff_w = wid - len);
}

void	parse_flags(t_p_buf *tmp, char *start)
{
	int		i;

	i = 6;
	while (i--)
		tmp->flag[i] = 0;
	while (start != tmp->end_find)
	{
		if (*start == '#' && tmp->flag[SHARP] == 0)
			tmp->flag[SHARP] = 1;
		else if (*start == '0' && tmp->flag[NOLL] == 0)
			tmp->flag[NOLL] = 1;
		else if (*start == '-' && tmp->flag[MINUS] == 0)
			tmp->flag[MINUS] = 1;
		else if (*start == '+' && tmp->flag[PLUS] == 0)
			tmp->flag[PLUS] = 1;
		else if (*start == ' ' && tmp->flag[SPACE] == 0)
			tmp->flag[SPACE] = 1;
		start++;
	}
	i = 6;
	while (i--)
		if (tmp->flag[i] == 1)
			return ;
	tmp->flag[NO_FLAG] = 1;
}
