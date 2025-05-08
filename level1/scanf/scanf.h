/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:24:20 by msidry            #+#    #+#             */
/*   Updated: 2025/05/08 23:33:26 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANF_H
# define SCANF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <ctype.h>



int	ft_scanf(const char *format, ...);

#endif // SCANF_H