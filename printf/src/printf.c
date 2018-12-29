/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 17:20:36 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* write get_data */

char	*parse_arg(t_flag flags, char *format, va_list *args)
{
	if (*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			|| *format == 'x' || *format == 'X')
		return (parse_numbers(*format, flags, args));
	if (*format == 'c' || *format == 's')
		return (parse_chars(*format, flags, args));
	/* p; */
}

char	*get_data(va_list *args, char *format);
{
	char	*string;
	t_flag	flags;

	string = NULL;
	flags = newflag(void);
	flags = set_flags(&flags, ++format);
	return (parse_arg(flags, format, args));
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	args;

	va_start(list, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
		}
		if (*format == '%')
		{
			ft_putstr(get_data(&args, (char *)format));
			format += flag_skip(format);
			/* figure out how to make args skip to next arg */
		}
		format++;
	}
	return (0);
}
