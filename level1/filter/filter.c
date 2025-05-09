/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:51:17 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 01:43:40 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filter.h"




int main(int argc, char *argv[])
{
    char *str;
    char *buffer;
    int bytes;

    if (argc != 2 || !argv[1][0])
    {
        write(2, INVERR, ft_strlen(INVERR));
        return (1);
    }
    if (read(0, NULL, 0) < 0)
    {
        perror("Error");
        return (1);
    }
    str = calloc(BUFFER_SIZE, sizeof(char));
    if (!str)
    {
        perror("Error");
        return (1);
    }
    buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
    {
        free(str);
        perror("Error");
        return (1);
    }
    while (1)
    {
        bytes = read(0, buffer, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(str);
            free(buffer);
            perror("Error");
            return (1);
        }
        if (bytes == 0)
            break ;
        buffer[bytes] = '\0';
        str = realloc(str, ft_strlen(str) + bytes + 1);
        ft_strlcpy(str + ft_strlen(str), buffer, bytes + 1);
    }
    free(buffer);
    findrepalce(str, argv[1], '*');
    write (1, str, ft_strlen(str));
    free(str);
    //atexit(ll);TODO: LEAK CHECK !
    return (0);
}


int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}


size_t ft_strlcpy(char *dest, char *src, size_t size)
{
    size_t i;

    i = 0;
    if (!dest || !src)
        return ft_strlen(src);
    if (size > 0)
    {
        while (src[i] && i < size - 1)
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (i);
}


void findrepalce(char *src, char *target, char token)
{
    int i;
    int j;
    int k;

    i = 0;

    while (src[i])
    {
        j = 0;
        k = i;
        while (target[j] == src[k])
        {
            j++;
            k++;
        }
        if (!target[j])
        {
            while (i < k)
            {
                src[i] = token;
                i++;
            }
        }
        i++;
    }
}



void ll(void)
{
    system("leaks a.out");
}