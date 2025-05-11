/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:55:40 by msidry            #+#    #+#             */
/*   Updated: 2025/05/11 21:27:36 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef N_QUEEN_H
# define N_QUEEN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define ERRARGS "Error : Invalid Input !\n"
# define ERRMEMO "Error : Could not Allocate Memory !\n"

size_t ft_strlen(char *str);
int ft_isnumber(char *strnbr);
int ft_isspace(int c);
int ft_issign(int c);
int ft_isdigit(int c);
int ft_atoi(char *strnbr);
void solve_nqueen(int *solutions, int col, int size);
int ft_issafe(int *solutions, int col, int row);
void ft_printsolution(int *solutions, int size);
#endif //N_QUEEN_H