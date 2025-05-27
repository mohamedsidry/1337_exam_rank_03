/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:22:59 by msidry            #+#    #+#             */
/*   Updated: 2025/05/11 23:55:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERSET_H
# define POWERSET_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define ERRMEMO "Error : Could not allocate memory !\n"
# define ERRARGS "Error : Invalid input numbers !\n"
size_t ft_strlen(char *str);
int ft_isnumber(char *strnbr);
int ft_isspace(int c);
int ft_issign(int c);
int ft_isdigit(int c);
int ft_atoi(char *strnbr);
int ft_validinput(char *subsetstrs[]);


#endif // POWERSET_H