/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:02:55 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:24:52 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		new[i] = f(i, p[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
