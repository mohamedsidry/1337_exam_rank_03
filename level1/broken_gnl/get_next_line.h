/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:54:53 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 15:47:24 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif // BUFFER_SIZE
char *get_next_line(int fd);
char *ft_strchr(char *str, int c);
void *ft_calloc(size_t count, size_t size);
size_t ft_strlcpy(char *dest, char *src, size_t size);
char *ft_strdup(char *str);
size_t ft_strlen(char *str);
char *getfullline(int fd, char **buffer);
char *ft_merge(char **buffer, char *newread);
char *getcurrentline(char *buffer);
void resetbuffer(char **buffer,char **line);
#endif //GET_NEXT_LINE_H