/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:54:56 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 16:03:07 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    line = NULL;
    
    if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (free(buffer), buffer = NULL, NULL);
    if (!buffer || !ft_strchr(buffer, '\n'))
        buffer = getfullline(fd, &buffer);
    if (!buffer || !buffer[0])
        return (free(buffer), buffer = NULL , NULL);
    line = getcurrentline(buffer);
    resetbuffer(&buffer, &line);
    return (line);
}



char *getfullline(int fd, char **buffer)
{
    char *holder;
    size_t bytes;
    
    holder = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!holder)
        return(free(buffer), *buffer = NULL , NULL);
    while (1)
    {
        bytes = read(fd, holder, BUFFER_SIZE);
        if (bytes == 0)
            break ;
        holder[bytes] = '\0';
        *buffer = ft_merge(buffer, holder);
        if (!(*buffer))
            return (NULL);
        if (ft_strchr(holder, '\n'))
            break ;
    }
    free(holder);
    return (*buffer);
}



char *ft_merge(char **buffer, char *newread)
{
    char *newbuffer;
    size_t newbuffersize;
    size_t idx;
    
    if (!(*buffer))
    {
        *buffer = ft_strdup(newread);
        return (*buffer);        
    }
    newbuffersize = ft_strlen(*buffer) + ft_strlen(newread) + 1;
    newbuffer = ft_calloc(newbuffersize, sizeof(char));
    if (!newbuffer)
    {
        free(*buffer);
        *buffer = NULL;
        free(newread);
        return (NULL);
    }
    idx = ft_strlcpy(newbuffer, *buffer, ft_strlen(*buffer) + 1);
    ft_strlcpy(newbuffer + idx, newread, ft_strlen(newread) + 1);
    free (*buffer);
    *buffer = NULL;
    return (newbuffer);
}

char *getcurrentline(char *buffer)
{
    char *ptr;
    char *line;

    ptr = ft_strchr(buffer, '\n');
    if (!ptr)
    {
        line = ft_strdup(buffer);
        return (line);
    }
    ptr++;
    line = ft_calloc(ptr - buffer + 1, sizeof(char));
    if (!line)
        return (NULL);
    ft_strlcpy(line, buffer, ptr - buffer + 1);
    return (line);
}

void resetbuffer(char **buffer,char **line)
{
    char *start;
    char *end;
    char *newbuffer;

    start = ft_strchr(*buffer, '\n');
    if (!start)
    {
        free(*buffer);
        *buffer = NULL;
        return ;
    }
    start++;
    end = ft_strchr(*buffer, '\0');
    newbuffer = ft_calloc(end - start + 1, sizeof(char));
    if (!newbuffer)
    {
        free(*buffer);
        free(*line);
        *buffer = NULL;
        *line = NULL;
        return;
    }
    ft_strlcpy(newbuffer, start, end - start + 1);
    free(*buffer);
    *buffer = newbuffer;
}


