/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenia <ksenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:45:50 by ksenia            #+#    #+#             */
/*   Updated: 2019/10/06 18:51:13 by ksenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	unsigned char	*new;
	unsigned char	*frm;

	new = (unsigned char*)dst;
	frm = (unsigned char*)src;
	while (n-- > 0)
		*(new++) = frm[n];
	return (dst);
}
