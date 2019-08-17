/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:41:33 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:25:45 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*new;
	char	*frm;

	frm = (char*)s1;
	res = (char*)malloc(sizeof(char) * (ft_strlen(frm) + 1));
	if (!res)
		return (0);
	new = res;
	while (*frm)
		*(new++) = *(frm++);
	*new = '\0';
	return (res);
}
