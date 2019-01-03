/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:25 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/02 17:42:19 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

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

int		set_first(t_flag **input, char *format)
{
	t_flag	*flags;

	flags = *input;
	while (*format && (*format == '-' || *format == ' ' || *format == '0' ||
				*format == '#'))
	{
		if (*format == '-')
			flags->dash = 1;
		if (*format == ' ')
			flags->space = 1;
		if (*format == '0')
			flags->zero = 1;
		/* verify how 0 flag works */
		if (*format == '#')
			flags->sharp = 1;
		format++;
	}
	return (1);
}

int		set_width(t_flag **input, char *format, va_list *args)
{
	t_flag	*flags;

	flags = *input;
	while (*format && (('0' <= *format && *format <= '9') || *format == '*' || *format == '.'))
	{
		if ('0' <= *format && *format <= '9')
		{
			if (*format == '0')
				flags->zero = 1;
			flags->width = set_width_and_prec(format, args);
			format += skip_nums(format);
		}
		if (*format == '.')
		{
			flags->dot = 1;
			flags->prec = set_width_and_prec(++format, args);
			format += skip_nums(format);
		}
		if (*format == '-')
			flags->dash = 1;
		if (*format == ' ')
			flags->space = 1;
		if (*format == '#')
			flags->sharp = 1;
		if (!(*format && (('0' <= *format && *format <= '9') || *format == '*' || *format == '.')))
			break ;
		format++;
	}
	return (1);
}

int		set_width_and_prec(char *format, va_list *args)
{
	if (*format == '*')
		return (va_arg(*args, int));
	else if ('0' <= *format && *format <= '9')
		return (ft_atoi(format));
	return (0);
}

int		set_length(t_flag **input, char *format)
{
	t_flag	*flags;

	flags = *input;
	if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			flags->ll = 1;
		else
			flags->l = 1;
	}
	if (*format == 'L')
		flags->L = 1;
	return (1);
}
