/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:50:27 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/27 19:45:12 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*parse_numbers(char c, t_flag *flags, va_list *args)
{
	if ((flags->h) || (flags->hh))
		return (handle_h(c, flags, args));
	if ((flags->l) || (flags->ll))
		return (handle_l(c, flags, args));
	return (format_string(get_num(c, va_arg(*args, int), flags), flags, c));
}

char	*parse_chars(char c, t_flag *flags, va_list *args)
{
	char		*s;
	if (c == 'c')
	{
		s = (char *)malloc(sizeof(char) * 2);
		s[0] = (char)va_arg(*args, int);
		s[1] = 0;
		return (format_string(s, flags, c));
	}
	if (c == 's')
	{
		return (format_string(va_arg(*args, char *), flags, c));
	}
	return (NULL);
}

char	*parse_float(char c, t_flag *flags, va_list *args)
{
	long double	f;

	if (flags->L)
		f = va_arg(*args, long double);
	else
		f = va_arg(*args, double);
	return (format_string(ft_ftoa(f), flags, c));
}
