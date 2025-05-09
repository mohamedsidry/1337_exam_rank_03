/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pernutation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:21:01 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 18:03:35 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERNUTATION_H
# define PERNUTATION_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define ENVERR "Error : Invalid Arguments !\n"
# define MEMERR "Error : Memory Allocation !\n"
size_t ft_strlen(char *str);
char *ft_strdup(char *str);
void *ft_calloc(size_t count, size_t size);
size_t ft_strlcpy(char *dst, char *src, size_t n);
size_t factorial(size_t number);
void ft_swap(char *a, char *b);
int ft_strcmp(char *str1, char *str2);

void permutation(char *str, size_t start, size_t end, char **solutions);
char *addtostack(char **stack, char *solution);
void printsolutions(char **solutions);
void sortsolutions(char **solutions);
void freesolutions(char **solutions);
#endif // PERNUTATION