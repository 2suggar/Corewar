/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzboncak <dzboncak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 23:09:42 by bkiehn            #+#    #+#             */
/*   Updated: 2019/03/07 20:20:20 by dzboncak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(char c)
{
	char	*res;

	res = ft_strnew(1);
	res[0] = c;
	return (res);
}

char	*add_char(char *str, char c, int n)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str) + n);
	tmp = ft_strcpy(tmp, str);
	ft_memset(tmp + ft_strlen(str), c, n);
	free(str);
	return (tmp);
}

char	*add_char2zero(char *str, char c, int n)
{
	char	*tmp;
	int		real_len;

	real_len = ft_strlen(str + 1) + 1;
	tmp = ft_strnew(real_len + n);
	tmp = ft_memcpy(tmp, str, real_len);
	ft_memset(tmp + real_len, c, n);
	free(str);
	return (tmp);
}

char	*plus_prec(t_p_buf *p_str, char *str, char c, int count)
{
	char	*start_ptr;
	int		len;

	len = ft_strlen(p_str->f_str);
	start_ptr = str;
	start_ptr = ft_strsub(p_str->f_str, 1, len - 1);
	start_ptr = char_add(start_ptr, c, count + 1);
	start_ptr = char_add(start_ptr, '+', 1);
	return (start_ptr);
}

char	*char_add(char *str, char c, int n)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(str) + n);
	ft_strcpy(tmp + n, str);
	ft_memset(tmp, c, n);
	free(str);
	return (tmp);
}
