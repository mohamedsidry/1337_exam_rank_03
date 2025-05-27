/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:25:25 by msidry            #+#    #+#             */
/*   Updated: 2025/05/11 23:54:16 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.h"


void solve_subsets(int *arr, int len, int target, int *subset, int subset_size, int sum, int pos);
int main(int argc, char *argv[])
{
    int *subsets;
    int *values;
    int valuescount;
    int idx;
    int target;

    idx = 0;
    valuescount = argc - 2;
    if (argc < 3 || !ft_validinput(&argv[1]))
    {
        write(2, ERRARGS, ft_strlen(ERRARGS));
        return (1);
    }
    values = (int *)malloc(sizeof(int) * valuescount);
    if (!values)
    {
        write(2, ERRMEMO, ft_strlen(ERRMEMO));
        return (1);
    }
    subsets = (int *)malloc(sizeof(int) * valuescount);
    if (!subsets)
    {
        free(values);
        write(2, ERRMEMO, ft_strlen(ERRMEMO));
        return (1);
    }
    while (argv[2 + idx])
    {
        values[idx] = ft_atoi(argv[2 + idx]);
        idx++;
    }
    target = ft_atoi(argv[1]);
    solve_subsets(values, valuescount, target, subsets, 0,0,0);
    free(subsets);
    free(values);
    return (0);
}

void solve_subsets(int *arr, int len, int target, int *subset, int subset_size, int sum, int pos) 
{
    if (sum == target && subset_size > 0) 
    {
        for (int i = 0; i < subset_size; i++)
        {
            if (i > 0) 
                printf(" ");
            printf("%d", subset[i]);
        }
        printf("\n");
    }
    
    for (int i = pos; i < len; i++) 
    {
        if(i > pos && arr[i] == arr[i - 1])
            continue;
        subset[subset_size] = arr[i];
        solve_subsets(arr, len, target, subset, subset_size + 1, sum + arr[i], i + 1);
    }
}






