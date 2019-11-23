/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:27:31 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/07 20:16:41 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_flags(t_p_buf *p_str, char *prev_str)
{
	char	*tmp;
	int		diff;

	tmp = prev_str;
	if (p_str->flag[PLUS] && p_str->flag[NOLL] && (prev_str[0] != '+' &&
	prev_str[0] != '-') && p_str->precision == -1)
		p_str->width -= 1;
	diff = p_str->width - ft_strlen(prev_str);
	if ((p_str->precision == -1 && p_str->flag[NOLL] && !p_str->flag[MINUS]) ||
	(p_str->d_type == FLOAT && p_str->flag[NOLL]))
		wid_to_sign(p_str, diff, &tmp, prev_str);
	else if (p_str->f_str[0] != '-' && !p_str->flag[MINUS] &&
	p_str->flag[SPACE] && p_str->d_type != U_DEC)
		return (tmp = char_add(tmp, ' ', 1));
	if (p_str->precision == -1 && p_str->flag[NOLL] && p_str->flag[PLUS])
	{
		if (prev_str[0] == '+')
			tmp = plus_prec(p_str, tmp, '0', diff - 1);
		else if (prev_str[0] == '-')
			tmp = min_prec(p_str, tmp, '0', diff - 1);
	}
	if (prev_str[0] != '-' && p_str->flag[PLUS] && p_str->d_type != U_DEC)
		return (tmp = char_add(tmp, '+', 1));
	return (tmp);
}

char	*hex_oct_flags(t_p_buf *p_str, char *prev_str)
{
	char	*tmp;
	int		diff_p;
	int		diff_w;

	tmp = prev_str;
	calc_diff_w(p_str, prev_str, &diff_w, &diff_p);
	if (p_str->flag[NOLL] && !p_str->flag[MINUS] &&
	p_str->precision == -1)
		tmp = char_add(tmp, '0', diff_w);
	if ((p_str->d_type == HEX && p_str->flag[SHARP] &&
	diff_p >= 0 && p_str->data.i != 0) || p_str->flag[EXC])
	{
		tmp = char_add(tmp, 'x', 1);
		tmp = char_add(tmp, '0', 1);
	}
	else if (p_str->d_type == HEX_B && p_str->flag[SHARP] &&
	diff_p >= 0 && p_str->data.i != 0)
	{
		tmp = char_add(tmp, 'X', 1);
		tmp = char_add(tmp, '0', 1);
	}
	else if (p_str->d_type == OCT && p_str->flag[SHARP] &&
	p_str->data.i != 0 && (diff_p > 0 || p_str->width == -1))
		tmp = char_add(tmp, '0', 1);
	return (tmp);
}

char	*use_flags(t_p_buf *p_str, char *prev_str)
{
	if (p_str->d_type == STR || p_str->d_type == CHAR)
		return (prev_str);
	else if (p_str->d_type == DEC || p_str->d_type == U_DEC ||
	p_str->d_type == FLOAT)
		return (dec_flags(p_str, prev_str));
	else if (p_str->d_type >= OCT && p_str->d_type <= HEX_B)
		return (hex_oct_flags(p_str, prev_str));
	return (prev_str);
}

char	*use_width(t_p_buf *p_str, char *prev_s)
{
	int		to_add;
	char	*tmp;

	if (prev_s[0] == '\0' && p_str->d_type == CHAR)
		to_add = p_str->width - 1;
	else
		to_add = p_str->width - ft_strlen(prev_s);
	tmp = prev_s;
	if (to_add <= 0)
		return (prev_s);
	else
	{
		if (p_str->d_type == CHAR && p_str->flag[MINUS] && prev_s[0] == '\0')
		{
			return (add_char2zero(tmp, ' ', to_add));
		}
		if (p_str->flag[MINUS])
		{
			return (add_char(tmp, ' ', to_add));
		}
		return (char_add(tmp, ' ', to_add));
	}
	return (tmp);
}

char	*use_flags_and_width(t_p_buf *p_str, char *prec_s)
{
	char	*tmp;

	tmp = prec_s;
	tmp = use_flags(p_str, tmp);
	tmp = use_width(p_str, tmp);
	return (tmp);
}
