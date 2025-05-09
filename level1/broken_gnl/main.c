/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:55:07 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 15:56:34 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ll(void)
{
    system("leaks a.out");
}
int main(void)
{
    char *line;
    int fd;
    int idx;
    
    fd = 0;
    idx = 0;
    while (1)
    {
        line = get_next_line(fd);
        printf("%d : %s", idx++, line);
        if (!line)
            break;
        free(line);
    }
    atexit(ll);
    return (0);
}