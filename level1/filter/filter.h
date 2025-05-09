/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:51:41 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 01:45:17 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTER_H
# define FILTER_H

# include <unistd.h> // for write 
# include <stdlib.h> // for free
# include <stdio.h> // for perror
# define INVERR "Error : Invalid arguments !"
# define BUFFER_SIZE 1
int ft_strlen(char *str);
size_t ft_strlcpy(char *dest, char *src, size_t size);
void findrepalce(char *src, char *target, char token);
void ll(void);

# endif // FILTER_H