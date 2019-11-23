/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiehn <bkiehn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:51:47 by dzboncak          #+#    #+#             */
/*   Updated: 2019/03/12 17:12:04 by bkiehn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_char(char c, t_p_buf *p_str)
{
	if (c == 'd' || c == 'i')
		return (p_str->d_type = DEC);
	else if (c == 's')
		return (p_str->d_type = STR);
	else if (c == 'p')
		return (p_str->d_type = PTR);
	else if (c == 'c')
		return (p_str->d_type = CHAR);
	else if (c == 'o' || c == 'x' || c == 'X')
		return (hex_oct_types(c, p_str));
	else if (c == 'u')
		return (p_str->d_type = U_DEC);
	else if (c == 'f')
		return (p_str->d_type = FLOAT);
	else if (c == 'U' || c == 'O' || c == 'D')
		return (addtnl_types(c, p_str));
	else if (c == '%')
	{
		p_str->data.c = '%';
		return (p_str->d_type = CHAR);
	}
	return (0);
}

int		hex_oct_types(char c, t_p_buf *p_str)
{
	if (c == 'o')
		return (p_str->d_type = OCT);
	else if (c == 'x')
		return (p_str->d_type = HEX);
	else if (c == 'X')
		return (p_str->d_type = HEX_B);
	return (0);
}

int		addtnl_types(char c, t_p_buf *p_str)
{
	p_str->d_length = l;
	if (c == 'U')
		return (p_str->d_type = U_DEC);
	else if (c == 'D')
		return (p_str->d_type = DEC);
	else if (c == 'O')
		return (p_str->d_type = OCT);
	return (0);
}

void	write_type(t_p_buf *p_str, va_list *ap)
{
	if (p_str->d_type == DEC || p_str->d_type == OCT || p_str->d_type == HEX
	|| p_str->d_type == HEX_B || p_str->d_type == U_DEC || p_str->d_type == PTR)
		p_str->data.i = (long long int)va_arg(*ap, long long int);
	else if (p_str->d_type == STR)
	{
		p_str->data.str = (char*)va_arg(*ap, char*);
		if (p_str->data.str == NULL)
			p_str->data.str = ft_strdup("(null)");
	}
	else if (p_str->d_type == CHAR && p_str->data.c != '%')
		p_str->data.c = (unsigned char)va_arg(*ap, int);
}

char	*find_type(t_p_buf *p_str, char *s, va_list *ap)
{
	while (!type_char(*s, p_str) && *s != '\0')
	{
		s++;
	}
	p_str->end_find = s;
	if (*s == '\0')
	{
		p_str->d_type = STR;
		p_str->data.str = "\0";
		return (s);
	}
	write_type(p_str, ap);
	return (s);
}
