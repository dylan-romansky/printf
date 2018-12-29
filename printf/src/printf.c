/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 20:34:42 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* write float printing code */

char	*str_to_arg(char *format)
{
	char	*s;
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	s = ft_strsub(format, 0, i);
	return (s);
}

char	*parse_arg(t_flag flags, char *format, va_list *args)
{
	if (*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			|| *format == 'x' || *format == 'X')
		return (parse_numbers(*format, flags, args));
	if (*format == 'c' || *format == 's')
		return (parse_chars(*format, flags, args));
	/* 
	if (*format == 'p')
		return (parse_pointer(*format, flags, args));
		*/
	return (NULL);
}

char	*get_data(va_list *args, char *format);
{
	t_flag	flags;

	string = NULL;
	flags = newflag(void);
	flags = set_flags(&flags, ++format);
	return (parse_arg(flags, format, args));
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	args;
	char	*string;
	char	*buf;

	va_start(args, format);
	string = ft_strnew(0);
	while (*format)
	{
		buf = str_to_arg(format);
		format += ft_strlen(buf);
		string = ft_strjoin(string, buf);
		free (buf);
		if (!(*format))
			break ;
		string = ft_strjoin(string, get_data(&args, format));
		format += flag_skip(format);
	}
	va_end(args);
	free (buf);
	ft_putstr(string);
	free (string);
	return (0);
}
