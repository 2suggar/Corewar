/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:35:55 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/07 20:28:02 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wid_to_sign(t_p_buf *p_str, int diff, char **tmp, char *prev_str)
{
	if (p_str->width != -1 && diff > 1)
	{
		if (p_str->f_str[0] == '-')
			*tmp = min_prec(p_str, *tmp, '0', diff - 1);
		else if (prev_str[0] == '+')
			*tmp = plus_prec(p_str, *tmp, '0', diff - 1);
		else if (p_str->flag[SPACE] && !p_str->flag[PLUS] &&
		prev_str[0] != '+' && prev_str[0] != '-')
			*tmp = char_add(*tmp, '0', diff - 1);
		else
			*tmp = char_add(*tmp, '0', diff);
	}
}

void	set_diff_p(t_p_buf *p_str, int *diff_p, int *wid, int *len)
{
	if (p_str->width == -1)
		*wid = *len;
	else
		*wid = p_str->width;
	if (p_str->precision != -1)
		*diff_p = *len - p_str->precision;
	else if (p_str->precision == -1 && p_str->flag[SHARP]
	&& p_str->d_type == OCT)
		*diff_p = 1;
	else
		*diff_p = 0;
}

char	*min_prec(t_p_buf *p_str, char *str, char c, int count)
{
	char	*start_ptr;
	int		len;

	len = ft_strlen(p_str->f_str);
	start_ptr = str;
	start_ptr = ft_strsub(p_str->f_str, 1, len - 1);
	start_ptr = char_add(start_ptr, c, count + 1);
	start_ptr = char_add(start_ptr, '-', 1);
	return (start_ptr);
}

char	*exceptions_hex(t_p_buf *p_str)
{
	if ((p_str->d_type != HEX && p_str->d_type != HEX_B))
		return (ft_strdup("0"));
	else if ((p_str->d_type == HEX || p_str->d_type == HEX_B)
	&& p_str->precision == -1)
		return (ft_strdup("0"));
	else
	{
		if ((p_str->d_type >= OCT && p_str->d_type <= HEX_B))
			p_str->flag[SHARP] = 0;
		return (ft_strdup("\0"));
	}
}

char	*check_width(t_p_buf *p_str, char *prec_s)
{
	char	*tmp;

	tmp = prec_s;
	if (p_str->flag[PLUS] && p_str->flag[SPACE])
		p_str->flag[SPACE] = 0;
	if (p_str->flag[NO_FLAG])
		tmp = use_width(p_str, prec_s);
	else
		tmp = use_flags_and_width(p_str, prec_s);
	return (tmp);
}
