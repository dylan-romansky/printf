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

char	*get_data(va_list *args, char *format);
{
	char	*string;
	t_flag	flags;

	string = NULL;
	flags = newflag(*args);
	flags = set_flags(flags, ++format);
	while (!(*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			*format == 'x' || *format == 'X' || *format == 'c' || *format =='s'
			|| *format == 'p' || *format == 'f'))
		format++;
	return (get_data(flags, format, args));
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
