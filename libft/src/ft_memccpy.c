/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:23:01 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:27:06 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;
	unsigned char	*frm;
	unsigned char	sym;

	sym = (unsigned char)c;
	new = (unsigned char*)dst;
	frm = (unsigned char*)src;
	i = 0;
	while (i++ < n)
	{
		*(new++) = *frm;
		if (*frm == sym)
		{
			return (new);
		}
		frm++;
	}
	return (NULL);
}
