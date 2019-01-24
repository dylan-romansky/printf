/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:19:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/22 13:02:54 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*get_num(char c, intmax_t i, t_flag *flags)
{
	if (c == 'd' || c == 'i')
		return (choose_string_maker(i, flags));
	if (c == 'o' || c == 'O')
		return (choose_ustring_maker(i, flags, 8));
	if (c == 'u' || c == 'U' || c == 'D')
		return (choose_ustring_maker(i, flags, 10));
	if (c == 'x' || c == 'X')
		return (choose_ustring_maker(i, flags, 16));
	if (c == 'b')
		return (choose_ustring_maker(i, flags, 2));
	return (NULL);
}

char	*handle_h(char c, t_flag *flags, va_list *args)
{
	short				i;
	unsigned short		s;
	char				g;
	unsigned char		u;

	if (flags->h)
	{
		if (c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
				c == 'D' || c == 'x' || c == 'X' || c == 'b')
		{
			s = (short)va_arg(*args, int);
			return (get_num(c, (int)s, flags));
		}
		i = (short)va_arg(*args, int);
		return (get_num(c, (int)i, flags));
	}
	if (flags->hh)
	{
		if (c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
				c == 'D' || c == 'x' || c == 'X' || c == 'b')
		{
			u = (char)va_arg(*args, int);
			return (get_num(c, u, flags));
		}
		g = (char)va_arg(*args, int);
		return (get_num(c, g, flags));
	}
	return (NULL);
}

char	*handle_ljz(char c, t_flag *flags, va_list *args)
{
	long				i;
	long long			j;
	intmax_t			m;
	ssize_t				z;

	if (flags->l)
	{
		i = va_arg(*args, long);
		return (get_num(c, i, flags));
	}
	if (flags->ll)
	{
		j = va_arg(*args, long long);
		return (get_num(c, j, flags));
	}
	if (flags->j)
	{
		m = va_arg(*args, intmax_t);
		return (get_num(c, m, flags));
	}
	if (flags->z)
	{
		z = va_arg(*args, ssize_t);
		return (get_num(c, z, flags));
	}
	return (NULL);
}
