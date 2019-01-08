/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:18:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/04 16:02:43 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		percentflag(char *format)
{
	int		i;

	i = 0;
	if (*format == '%')
	{
		if (*(format + 1) == '%')
			return (1);
		else if (*(format - 1) == '%')
			return (-1);
		else
		{
			format++;
			i++;
		}
	}
	while (*format && !(*format == 'd' || *format == 'i' || *format == 'u' ||
				*format == 'o' || *format == 'x' || *format == 'X' ||
				*format == 'c' || *format == 's' || *format == 'p' ||
				*format == 'f' || *format == '%'))
	{
		format++;
		i++;
	}
	if (*format == '%')
		return (i);
	return (0);
}

int		prec(char *format, va_list *args, t_flag **input)
{
	t_flag	*flags;

	flags = *input;
	flags->dot = 1;
	flags->prec = set_width_and_prec(++format, args);
	return (skip_nums(format));
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
	if (*format == 'h' || *format == 'l' || *format == 'L')
	{
		if (!set_length(flags, format++))
			return (0);
	}
	return (1);
}

int		set_flags(t_flag **flags, char *format, va_list *args)
{
	if (*format == '-' || *format == ' ' || *format == '0' || *format == '#')
	{
		if (!set_first(flags, format))
			return (0);
		while (*format == '-' || *format == ' ' || *format == '0' ||
				*format == '#')
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

int		initflags(t_flag **input)
{
	t_flag	*new;

	new = *input;
	if (new != NULL)
	{
		new->h = 0;
		new->hh = 0;
		new->l = 0;
		new->ll = 0;
		new->L = 0;
		new->f = 0;
		new->percent = 0;
		new->sharp = 0;
		new->zero = 0;
		new->dash = 0;
		new->space = 0;
		new->dot = 0;
		new->prec = 0;
		new->width = 0;
		return (1);
	}
	return (0);
}
