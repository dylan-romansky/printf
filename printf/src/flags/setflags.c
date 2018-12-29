/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:25 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 17:20:41 by dromansk         ###   ########.fr       */
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

t_flag	set_first(t_flag **input, char *format, va_list *args)
{
	t_flag	*flags;

	flags = *input;
	while (*format && (*format == '-' || *format == ' ' || *format == '0' ||
				*format == '#'))
	{
		if ('0' <= *format && *format <= '9')
		{
			if (*format == '0')
				flags->zero = 1;
			flags->width = set_width/prec(format, args);
			format += skip_nums(format);
		}
		if (*format == '.')
		{
			flags->prec = set_width/prec(++format, args);
			format += skip_nums(format);
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

int		set_width/prec(char *format, va_list *args)
{
	if (*format == '*')
		return (va_arg(*args, int));
	else if ('0' <= *format && *format <= '9')
		return (ft_atoi(format));
	return (0);
}
