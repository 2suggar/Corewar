/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:32:34 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:24:49 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	res;

	d = 0;
	s = 0;
	while (dst[d])
		++d;
	while (src[s])
		++s;
	if (size < d)
		s += size;
	else
		s += d;
	res = s;
	s = 0;
	while (src[s] && d + 1 < size)
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (res);
}
