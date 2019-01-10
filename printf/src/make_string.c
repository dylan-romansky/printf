/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:45 by dromansk         ###   ########.fr       */
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
	return (ft_strsub(format, 0, i));
}

char	*parse_arg(t_flag *flags, char *format, va_list *args)
{
	if (*format == '%')
		return (format_string(ft_strdup("%"), flags, '%'));
	if (*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			|| *format == 'x' || *format == 'X')
		return (parse_numbers(*format, flags, args));
	if (*format == 'f')
		return (parse_float(*format, flags, args));
	if (*format == 'c' || *format == 's')
		return (parse_chars(*format, flags, args));
	if (*format == 'p')
		return (parse_pointer(*format, flags, args));
	return (NULL);
}

char	*get_data(va_list *args, char *format)
{
	t_flag	*flags;
	char	*s;

	if (!(flags = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	if (!initflags(&flags))
		return (NULL);
	if (!set_flags(&flags, ++format, args))
		return (NULL);
	format += flag_skip((format));
	s = parse_arg(flags, format, args);
	flag_del(&flags);
	return (s);
}

char	*make_string(const char *restrict format, va_list *args)
{
	char	*string;
	char	*buf;

	string = ft_strnew(0);
	while (*format)
	{
		buf = str_to_arg((char *)format);
		format += ft_strlen(buf);
		string = swap_n_free(ft_strjoin(string, buf), &string);
		free(buf);
		if (!(*format))
			break ;
		buf = get_data(args, (char *)format);
		string = swap_n_free(ft_strjoin(string, buf), &string);
		free(buf);
		format += flag_skip((char *)format) + 1;
	}
	return (string);
}
