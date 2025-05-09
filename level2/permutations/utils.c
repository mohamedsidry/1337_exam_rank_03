/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:21:29 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 18:05:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutation.h"



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


char *ft_strdup(char *str)
{
    char *new;
    
    if (!str)
        return (NULL);
    new = ft_calloc(ft_strlen(str) + 1, sizeof(char));
    if (!new)
        return (NULL);
    ft_strlcpy(new, str, ft_strlen(str) + 1);
    return (new);
}


void *ft_calloc(size_t count, size_t size)
{
    long fullsize;
    void *mem;
    char *ptr;
    long idx;

    fullsize = count * size;
    
    if (fullsize <= 0)
        return (NULL);
    mem = malloc(sizeof(char) * fullsize);
    if (!mem)
        return (NULL);
    ptr = mem;
    idx = 0;
    while (idx < fullsize)
    {
        *ptr = '\0';
        ptr++;
        idx++;
    }
    return (mem);
}




size_t ft_strlcpy(char *dst, char *src, size_t n)
{
    size_t idx;
    
    idx = 0;
    if (!dst || !src)
        return (ft_strlen(src));
    if (n > 0)
    {
        while (src[idx] && idx < n - 1)
        {
            dst[idx] = src[idx];
            idx++;
        }
        dst[idx] = '\0';
    }
    return (ft_strlen(src));
}



size_t factorial(size_t number)
{
    if (number == 1 || number == 0)
        return 1;
    return number * factorial(number - 1);
}


void ft_swap(char *a, char *b)
{
    char tmp;

    if (a && b)
    {
        tmp = *a;
        *a = *b; 
        *b = tmp;
    }
}


int ft_strcmp(char *str1, char *str2)
{
    if (!str1 || !str2 || (str1 == str2))
        return (0);
    while (*str1)
    {
        if (*str1 != *str2)
            return ((unsigned char)*str1 - (unsigned char)*str2);
        str1++;
        str2++;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}