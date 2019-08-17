/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:57:38 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:24:51 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*p;
	char			*new;
	unsigned int	i;

	if (!s)
		return ((char*)s);
	new = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	p = (char*)s;
	i = 0;
	while (p[i])
	{
		new[i] = f(p[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
