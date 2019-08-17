/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rejoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:55:17 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:26:08 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rejoin(char *a, char *b)
{
	char	*new;

	new = ft_strjoin(a, b);
	free(a);
	free(b);
	a = NULL;
	b = NULL;
	return (new);
}
