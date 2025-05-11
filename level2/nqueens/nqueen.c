/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:55:37 by msidry            #+#    #+#             */
/*   Updated: 2025/05/11 21:31:10 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nqueen.h"


void ll()
{
    system("leaks a.out");
}

int main(int argc, char *argv[])
{
    int numberofqueens;
    int *solutions;
    
    if (argc != 2 || !argv[1][0] || !ft_isnumber(argv[1]))
    {
        write(2, ERRARGS, ft_strlen(ERRARGS));
        return (1);
    }
    numberofqueens = ft_atoi(argv[1]);
    if (numberofqueens < 0)
    {
        write(2, ERRARGS, ft_strlen(ERRARGS));
        return (1);
    }
    solutions = (int *)malloc(sizeof(int) * numberofqueens);
    if (!solutions)
    {
        write (2, ERRMEMO, ft_strlen(ERRMEMO));
        return (2);
    }
    solve_nqueen(solutions, 0, numberofqueens);
    free(solutions);
    atexit(ll); //NOTE : checks for leaks !
    return (0);
}


void solve_nqueen(int *solutions, int col, int size)
{
    int row;
    if (col == size)
    {
        ft_printsolution(solutions, size);
        return ;
    }
    row = 0;

    while (row < size)
    {
        if (ft_issafe(solutions, col, row))
        {
            solutions[col] = row;
            solve_nqueen(solutions, col + 1, size);
        }
        row++;
    }
}


int ft_issafe(int *solutions, int col, int row)
{
    int i;
    
    i = 0;
    while (i < col)
    {
        if (solutions[i] == row || solutions[i] - row == col - i || row - solutions[i] == col - i)
            return (0);
        i++;
    }
    return (1);
}


void ft_printsolution(int *solutions, int size)
{
    int i;
    i = 0;
    while (i < size)
    {
        printf("%d", solutions[i]);
        i++;
    }
    printf("\n");
}