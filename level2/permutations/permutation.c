/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:20:58 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 18:05:12 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "permutation.h"

void ll(void)
{
    system("leaks a.out");
}
int main(int argc ,char *argv[])
{
    size_t solutions_count;
    char **solutions;
    size_t len;
    if (argc != 2 || !argv[1][0])
    {
        write(2, ENVERR, ft_strlen(ENVERR));
        return (1);
    }
    len = ft_strlen(argv[1]);
    solutions_count = factorial(len);
    solutions = ft_calloc(solutions_count + 1, sizeof(char *));
    if (!solutions)
    {
        write(2, MEMERR, ft_strlen(MEMERR));
        return (1);
    }
    permutation(argv[1], 0, len - 1, solutions);
    sortsolutions(solutions);
    printsolutions(solutions);
    freesolutions(solutions);
    //atexit(ll); TODO: CKECK LEAKS ! .
    return (0);
}

char *addtostack(char **stack, char *solution)
{
    static size_t next;

    stack[next] = ft_strdup(solution);
    if (!stack[next])
    {
        while (next >= 0)
        {
            free(stack[next]);
            stack[next] = NULL;
            next--;
        }
        return (NULL);
    }
    next++;
    return (stack[next - 1]);
}

void permutation(char *str, size_t start, size_t end, char **solutions)
{
    size_t i;

    if (start == end)
        addtostack(solutions, str);
    else
    {
        i = start;

        while (i <= end)
        {
            ft_swap(&str[start], &str[i]);
            permutation(str, start + 1, end, solutions);
            ft_swap(&str[start], &str[i]);
            i++;
        }
    }
}


void printsolutions(char **solutions)
{
    size_t idx;
    
    if (!solutions || !(*solutions))
        return ;
    idx = 0;
    while (solutions[idx])
    {
        puts(solutions[idx]);
        idx++;
    }
}

void sortsolutions(char **solutions)
{
    size_t idx;
    size_t jdx;
    char *tmp;
    
    idx = 0;
    if (!solutions || !(*solutions))
        return ;
    while (solutions[idx])
    {
        jdx = idx + 1;
        while (solutions[jdx])
        {
            if (ft_strcmp(solutions[idx], solutions[jdx]) > 0)
            {
                tmp = solutions[idx];
                solutions[idx] = solutions[jdx];
                solutions[jdx] = tmp;
            }
            jdx++;
        }
        idx++;
    }
}


void freesolutions(char **solutions)
{
    size_t idx;
    
    if (!solutions)
        return ;
    
    idx = 0;

    while (solutions[idx])
    {
        free(solutions[idx]);
        solutions[idx] = NULL;
        idx++;
    }
    free(solutions);
}