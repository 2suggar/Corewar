/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:00:25 by lcutjack          #+#    #+#             */
/*   Updated: 2019/07/21 15:21:23 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int ac, char **av)
{
    int fd;
    char line[1];
    char *start;
    unsigned char *lol;
    
    fd = open(av[1], O_RDONLY);
    while (read(fd, (void*)line, 1))
    {
        printf("%#x ", *(unsigned char*)line);
    }
    return 0;
}