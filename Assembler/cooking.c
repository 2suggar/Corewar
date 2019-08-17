/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:12:42 by lcutjack          #+#    #+#             */
/*   Updated: 2019/08/17 16:13:48 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void write_magic(int new)
{
    char    *lol;
    int     value;
    int     i;

    i = 4;
    value = COREWAR_EXEC_MAGIC;
    lol = (char*)&value;
    while (--i >= 0)
        write(new, lol + i, 1);
}

static void read_name(int fd, int new)
{
    char    name[PROG_NAME_LENGTH + 4];
    char    *line;
    char    *start;

    get_next_line(fd, &line);
    if (ft_strcmp(NAME_CMD_STRING, line))
    {
        ft_bzero(name, PROG_NAME_LENGTH);
        start = ft_strchr(line, '"');
        ft_strncpy(name, start + 1, ft_strchr(start + 1, '"') - start - 1);
    }
    write(new, name, PROG_NAME_LENGTH);
}

static void read_comment(int fd, int new)
{
    char comment[COMMENT_LENGTH + 4];
    char *line;
    char *start;

    get_next_line(fd, &line);
    if (ft_strcmp(COMMENT_CMD_STRING, line))
    {
        ft_bzero(comment, COMMENT_LENGTH);
        start = ft_strchr(line, '"');
        ft_strncpy(comment, start + 1, ft_strchr(start + 1, '"') - start - 1);
    }
    write(new, comment, COMMENT_LENGTH);
}



void cook_raw(int fd, int new)
{
    write_magic(new);
    read_name(fd, new);
    read_comment(fd, new);
    // read_code();
}
