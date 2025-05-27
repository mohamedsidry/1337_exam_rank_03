/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:00:01 by msidry            #+#    #+#             */
/*   Updated: 2025/05/11 23:39:18 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"



size_t ft_strlen(char *str)
{
    size_t len;

    len = 0;
    if (!str)
        return (0);
    
    while (str[len])
        len++;
    return (len);
}


int ft_isnumber(char *strnbr)
{
    if (!strnbr || !(*strnbr))
        return (0);
    while (*strnbr && ft_isspace(*strnbr))
        strnbr++;
    while (*strnbr && ft_issign(*strnbr))
        strnbr++;
    if (*strnbr && ft_isdigit(*strnbr))
        return (1);
    return (0);
}


int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}


int ft_issign(int c)
{
    return (c == '-' || c == '+');
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}


int ft_atoi(char *strnbr)
{
    long number;
    int sign;
    unsigned int max;

    number = 0;
    sign = 1;
    max = ~0;
    while (*strnbr && ft_isspace(*strnbr))
        strnbr++;
    while (*strnbr && ft_issign(*strnbr))
    {
        if (*strnbr == '-')
            sign *= -1;
        strnbr++;
    }
    while (*strnbr && ft_isdigit(*strnbr))
    {
        number = number * 10 + (*strnbr - 48);
        if ((unsigned int)number > max)
            return (-1);
        strnbr++;
    }
    return (number * sign);
}

int ft_validinput(char *subsetstrs[])
{
    int idx;

    idx = 0;
    while (subsetstrs[idx])
    {
        if (!ft_isnumber(subsetstrs[idx]))
            return (0);
        idx++;
    }
    return  (1);
}