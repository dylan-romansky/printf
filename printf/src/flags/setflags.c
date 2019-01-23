/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:04:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/22 19:07:11 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		set_flags(t_flag **flags, char *format, va_list *args)
{
	if (*format == '-' || *format == ' ' || *format == '0' || *format == '#'
			|| *format == '+')
	{
		if (!set_first(flags, format))
			return (0);
		while (*format == '-' || *format == ' ' || *format == '0' ||
				*format == '#' || *format == '+')
		{
			if (*format == '0' && *(format + 1) != '0')
				format++;
			else if (*format == '0' && *(format + 1) == '0')
			{
				format++;
				break ;
			}
			else
				format++;
		}
	}
	return (set_more_flags(flags, format, args));
}

int		set_first(t_flag **input, char *format)
{
	t_flag	*flags;

	flags = *input;
	while (*format && (*format == '-' || *format == ' ' || *format == '0' ||
				*format == '#' || *format == '+'))
	{
		if (*format == '-')
			flags->dash = 1;
		if (*format == ' ')
			flags->space = 1;
		if (*format == '0')
			flags->zero = 1;
		if (*format == '#')
			flags->sharp = 1;
		if (*format == '+')
			flags->plus = 1;
		format++;
	}
	return (1);
}

int		set_more_flags(t_flag **flags, char *format, va_list *args)
{
	if (*format == '*' || *format == '.' || ('0' <= *format && *format <= '9'))
	{
		if (!set_width(flags, format, args))
			return (0);
		while (*format == '*' || *format == '.' || ('0' <= *format &&
					*format <= '9'))
			format++;
	}
	if (*format == 'h' || *format == 'l' || *format == 'L' || *format == 'j'
			|| *format == 'z')
	{
		if (!set_length(flags, format++))
			return (0);
	}
	return (1);
}

int		prec(char *format, va_list *args, t_flag **input)
{
	t_flag	*flags;

	flags = *input;
	flags->dot = 1;
	format++;
	if (*format >= '0' && *format <= '9')
	{
		flags->prec = ft_atoi(format);
		while ('0' <= *format && *format <= '9')
			format++;
	}
	if (*format == '*')
	{
		flags->prec = va_arg(*args, int);
		format++;
	}
	if (*format >= '0' && *format <= '9')
		flags->prec = ft_atoi(format);
	if (flags->prec < 0)
	{
		flags->dot = 0;
		flags->prec = 0;
	}
	return (skip_nums(format) + 2);
}
