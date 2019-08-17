/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:43:09 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:24:55 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char*)s1;
	j = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (--n > 0 && *i && *j && *i == *j)
	{
		i++;
		j++;
	}
	return (*i - *j);
}
