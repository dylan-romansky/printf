/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:50:27 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 19:07:58 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "printstruct.h"

int		parse_arg(t_flag *flags, va_list *args, char **buf)
{
	int			i;

	i = convert_type_num(flags->type);
	if (i == 4)
		return (format_string(ft_strdup("%"), flags, buf));
	return (format_string(g_string[i].string(flags, args), flags, buf));
}

char	*parse_numbers(t_flag *flags, va_list *args)
{
	intmax_t	num;
	int			base;

	num = g_arglen[flags->size].parse(args);
	base = g_numconvert[flags->type].base;
	return (g_numconvert[flags->type].data(num, base));
}

char	*parse_chars(t_flag *flags, va_list *args)
{
	int			i;

	i = flags->size - 7;
	if (!i)
		return (get_string(args));
	return (get_char(args));
}

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
	size_t		ptr;
	void		*st;

	st = va_arg(*args, void *);
	if (!st)
		return (NULL);
	ptr = (size_t)st;
	return (ft_ltoa_base(p, 16));
}
