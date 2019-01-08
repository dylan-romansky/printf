/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:50:27 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/04 16:26:09 by dromansk         ###   ########.fr       */
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
	return (get_num(c, va_arg(*args, int), flags));
}

char	*parse_chars(char c, t_flag *flags, va_list *args)
{
	char		*s;

	s = NULL;
	if (c == 'c')
	{
		s = (char *)malloc(sizeof(char) * 2);
		s[0] = (char)va_arg(*args, int);
		s[1] = 0;
		return (format_string(s, flags, c));
	}
	if (c == 's')
	{
		free(s);
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
	if (!flags->dot)
	{
		flags->dot = 1;
		flags->prec = 6;
	}
	return (format_string(ft_ftoa(f, flags->prec), flags, c));
}

char	*parse_pointer(char c, t_flag *flags, va_list *args)
{
	size_t		p;
	char		*s;

	s = va_arg(*args, char *);
	p = (size_t)s;
	ft_strclr(s);
	free(s);
	return (format_string(ft_ltoa_base(p, 16), flags, c));
}
