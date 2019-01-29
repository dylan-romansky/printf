/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:50:27 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 13:20:11 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printffun.h"
#include "printfstruct.h"

char	*parse_numbers(t_flag *flags, va_list *args)
{
	intmax_t	num;
	int			base;

	num = g_arglen[flags->size].parse(args);
	base = g_numconvert[flags->type].base;
	return (g_numcovert[flags->type].data(num, base));
}

char	*parse_chars(t_flag *flags, va_list *args)
{
	int			i;

	i = flags->size - 7;
	if (!i)
		return (get_string(args));
	return (get_char(args));
}
/*	char		*s;

	s = NULL;
	if (c == 'c')
	{
		s = (char *)malloc(sizeof(char) * 2);
		s[0] = (char)va_arg(*args, int);
		s[1] = 0;
		return (s);
	}
	if (c == 's')
	{
		s = va_arg(*args, char *);
		return (ft_strdup(s));
	}
	return (NULL);
}*/

char	*parse_float(t_flag *flags, va_list *args)
{
	long double	f;

	if (flags->size == el)
		f = va_arg(*args, long double);
	else
		f = va_arg(*args, double);
	if (!flags->dot)
	{
		flags->dot = 1;
		flags->prec = 6;
	}
	return (ft_ftoa(f, flags->prec));
}

char	*parse_pointer(t_flag *flags, va_list *args)
{
	size_t		p;
	void		*st;

	st = va_arg(*args, void *);
	if (!st)
		return (NULL);
	p = (size_t)st;
	return (ft_ltoa_base(p, 16));
}
