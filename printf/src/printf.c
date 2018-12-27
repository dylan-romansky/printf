/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/19 14:42:05 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* write get_data */

char	*parse_arg(flags, format)
{
	if (*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			|| *format == 'x' || *format == 'X')
		return (parse_numbers(*format, flags));
	if (*format == 'c' || *format == 's')
		return (parse_chars(*format, flags));
	/* p; */
}

char	*get_data(va_list *args, char *format);
{
	char	*string;
	t_flag	flags;

	string = NULL;
	flags = newflag(*args);
	flags = set_flags(flags, ++format);
	format += flag_skip(format);
	return (parse_arg(flags, format));
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	args;

	va_start(list, format);
	while (*format)
	{
		if (*format == '')
		{
			ft_putchar(*(format++));
			ft_putchar(*format);
		}
		if (*format == '%')
			ft_putstr(get_data(&args, (char *)format));
		format++;
	}
	return (0);
}
