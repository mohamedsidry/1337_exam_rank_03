/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:54:58 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 02:50:29 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *str, int c)
{
    if (!str)
        return (NULL);
    while (*str && *str != (unsigned char)c)
        str++;
    if (*str == (unsigned char)c)
        return (str);
    return (NULL);
}

void *ft_calloc(size_t count, size_t size)
{
    void *result;
    char *ptr;
    long idx;
    long totalsize;

    idx = 0;
    totalsize = count * size;
    result = malloc(totalsize);
    if (!result)
        return (NULL);
    ptr = (char *)result;
    while (idx < totalsize)
    {
        *ptr = '\0';
        ptr++;
        idx++;
    }
    return (result);
}


size_t ft_strlcpy(char *dest, char *src, size_t size)
{
    size_t idx;

    idx = 0;
    if (!dest || !src)
        return (ft_strlen(src));
    
    if (size > 0)
    {
        while (src[idx] && idx < size - 1)
        {
            dest[idx] = src[idx];
            idx++;
        }
        dest[idx] = '\0';
    }
    return (idx);
}

char *ft_strdup(char *str)
{
    char *new;

    new = ft_calloc(ft_strlen(str) + 1, sizeof(char));
    if (!new)
        return (NULL);
    ft_strlcpy(new, str, ft_strlen(str) + 1);
    return (new);
}

size_t ft_strlen(char *str)
{
    size_t idx;

    idx = 0;
    if (!str)
        return (0);
    while (str[idx])
        idx++;
    return (idx);
}