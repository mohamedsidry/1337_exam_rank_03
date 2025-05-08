/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:25:45 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 00:33:39 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"



int main(void)
{
    int d1, d2, d3;
    char c1, c2, c3;
    char s1[] = "-42";
    char s2[] = "-42";
    char s3[] = "-42";
    d1 = -42;
    d2 = -42;
    d3 = -42;
    c1 = '-';
    c2 = '4';
    c3 = '1';
    int ret;

    ret = 0;

    ret = ft_scanf("%d %d %d", &d1, &d2, &d3);
    printf("values  :\n d1 = %d\n d2 = %d\n d3 = %d\n", d1, d2, d3);
    ret = ft_scanf("%c %c %c", &c1, &c2, &c3);
    printf("values  :\n c1 = %c\n c2 = %c\n c3 = %c\n", c1, c2, c3);
    ret = ft_scanf("%s %s %s", s1, s2, s3);
    printf("values  :\n s1 = %s\n s2 = %s\n s3 = %s\n", s1, s2, s3);
    printf("return : %d\n", ret);
    return (0);
}