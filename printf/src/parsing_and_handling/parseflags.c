/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:50:27 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/16 20:26:18 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*parse_numbers(char c, t_flag *flags, va_list *args)
{
	if (c == 'U' || c == 'O' || c == 'D')
	{
		flags->l = 1;
		return (handle_ljz(c, flags, args));
	}
	if (flags->h || flags->hh)
		return (handle_h(c, flags, args));
	if (flags->l || flags->ll || flags->j || flags->z)
		return (handle_ljz(c, flags, args));
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
		return (s);
	}
	if (c == 's')
	{
		s = va_arg(*args, char *);
		return (ft_strdup(s));
	}
	return (NULL);
}

char	*parse_float(t_flag *flags, va_list *args)
{
	long double	f;

	if (flags->el)
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

char	*parse_pointer(char c, t_flag *flags, va_list *args)
{
	size_t		p;
	char		*s;

	s = va_arg(*args, char *);
	if (!s)
		return (NULL);
	p = (size_t)s;
	ft_strclr(s);
	free(s);
	return (ft_ltoa_base(p, 16));
}
