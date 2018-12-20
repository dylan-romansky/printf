/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:25 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/19 17:09:33 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		flag_skip(char *format)
{
	int		i;

	i = 0;
	while (!(*format == 'd' || *format == 'i' || *format == 'u' ||
				*format == 'o' || *format == 'x' || *format == 'X' ||
				*format == 'c' || *format == 's' || *format == 'p' ||
				*format == 'f'))
	{
		format++;
		i++;
	}
	return (i);
}

t_flag	set_first(t_flag *flags, char *format)
{
	while (*format && (*format == '-' || *format == ' ' || *format == '0' ||
				*format == '#'))
	{
		if (*format == '0')
		{
			flags->zero = 1;
			flags = set_width(flags, format);
			while (('0' <= *format && *format <= '9') || *format == '*')
				format++;
		}
		if (*format == '-')
			flags->dash = 1;
		if (*format == ' ')
			flags->space = 1;
		if (*format == '#')
			flags->sharp = 1;
		format++;
	}
	return (flags);
}

t_flag	set_width_prelim(t_flag *flags, char *format)
{
	if (*format == '.')
	{
		flags->prec = 1;
		format++;
		if (*format == '*')
		{
			flags->wild = 1;
			flags->width = -1;
		}
		else if(*format >= 0 && *format <= '9')
		{
			flags->width = ft_atoi(format);
		}
	}
	else if (*format == '*')
		flags->wild = 1;
	else if ('0' <= *format && *format <= '9')
		flags->width = ft_atoi(format);
	return (flags);
}
