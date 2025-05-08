/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:19:36 by msidry            #+#    #+#             */
/*   Updated: 2025/05/09 00:09:04 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanf.h"

int match_space(FILE *f)
{
    int _char;

    _char = fgetc(f);
    while (_char != EOF && isspace(_char))
        _char = fgetc(f);
    if (_char == EOF)
        return (-1);
    ungetc(_char, f);
    return (1);
}

int match_char(FILE *f, int c)
{
    int _char;

    _char = fgetc(f);
    if (_char == c)
    {
        ungetc(_char, f);
        return (1);
    }
    ungetc(_char, f);
    return (0);
}

int scan_string(FILE *f, va_list ap)
{
    int idx;
    char *ptr;
    char _char;

    ptr = va_arg(ap, char *);
    idx = 0;
    _char = fgetc(f);
    while (_char != EOF && !isspace(_char))
    {
        ptr[idx] = (unsigned char)_char;
        _char = fgetc(f);
        idx++;
    }
    if (idx == 0)
        return (-1);
    ptr[idx] = '\0';
    return (1);
}


int scan_int(FILE *f, va_list ap)
{
    int number;
    int sign;
    int _char;
    int match;
    int *ptr;

    number = 0;
    sign = 1;
    match = 0;

    while (match_char(f, '-') || match_char(f, '+'))
    {
        if (match_char(f, '-'))
            sign *= -1;
        _char = fgetc(f);
    }
    _char = fgetc(f);
    while (_char != EOF && isdigit(_char))
    {
        number = number * 10 + (_char - '0');
        _char = fgetc(f);
        match++;
    }
    if (_char != EOF)
        ungetc(_char, f);
    if (match == 0)
        return (0);
    ptr = va_arg(ap, int *);
    *ptr = number * sign;
    return (1);
}

int scan_char(FILE *f, va_list ap)
{
    int _char;
    char *ptr;

    ptr = va_arg(ap, char *);
    _char = fgetc(f);
    if (_char == EOF)
        return (0);
    *ptr = (unsigned char)_char;
    return (1);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int	nconv;
	int	c;

	nconv = 0;
	c = fgetc(f);
	if (c == EOF)
		return (EOF);
	ungetc(c, f);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break ;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break ;
		}
		else if (match_char(f, *format) != 1)
			break ;
		format++;
	}
	if (ferror(f))
		return (EOF);
	return (nconv);
}

int	ft_scanf(const char *format, ...)
{
    int ret;
    va_list ap;
    
    va_start(ap, format);
    ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
	return (ret);
}