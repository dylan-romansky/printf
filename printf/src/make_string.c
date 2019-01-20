/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/20 03:58:06 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*str_to_arg(char *format)
{
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	return (ft_strndup(format, i));
}

int		parse_arg(t_flag *flags, char *format, va_list *args, char **buf)
{
	if (*format == '%')
		return (format_string(ft_strdup("%"), flags, '%', buf));
	if (*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			|| *format == 'x' || *format == 'X' || *format == 'U'
			|| *format == 'b' || *format == 'O' || *format == 'D')
		return (format_string(parse_numbers(*format, flags, args), flags,
					*format, buf));
	if (*format == 'f' || *format == 'F')
		return (format_string(parse_float(flags, args), flags,
				*format, buf));
	if (*format == 'c' || *format == 's')
		return (format_string(parse_chars(*format, flags, args), flags,
				*format, buf));
	if (*format == 'p')
		return (format_string(parse_pointer(*format, flags, args), flags,
				*format, buf));
	return (0);
}

int		get_data(va_list *args, char *format, char **buf)
{
	t_flag	*flags;
	int		b;

	if (!(flags = (t_flag *)malloc(sizeof(t_flag))) ||
			!initflags(&flags) || !set_flags(&flags, ++format, args))
		return (error_handle(buf));
	if (!check_flag(format))
	{
		format += flag_skip(format);
		b = format_string(ft_strndup(format, 1), flags, 's', buf);
	}
	else
	{
		format += flag_skip(format);
		b = parse_arg(flags, format, args, buf);
	}
	flag_del(&flags);
	return (b);
}

int		make_string(const char *restrict format, va_list *args, int fd)
{
	char	*string;
	char	*buf;
	int		len;
	int		skip;

	string = ft_strnew(0);
	len = 0;
	skip = 0;
	while (*format)
	{
		buf = str_to_arg((char *)format);
		skip = ft_strlen(buf);
		format += skip;
		string = joining(&string, &buf, len, skip);
		len += skip;
		if (!(*format))
			break ;
		skip = get_data(args, (char *)format, &buf);
		string = joining(&string, &buf, len, skip);
		len += skip;
		format++;
		format += flag_skip((char *)format) + 1;
	}
	putnstr_fd(string, fd, len);
	free(string);
	return (len);
}
