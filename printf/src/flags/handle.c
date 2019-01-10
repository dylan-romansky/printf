/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:19:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/09 15:12:19 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*get_num(char c, intmax_t i, t_flag *flags)
{
	if (c == 'd' || c == 'i')
		return (format_string(choose_string_maker(i, flags), flags, c));
	if (c == 'o')
		return (format_string(choose_ustring_maker(i, flags, 8), flags, c));
	if (c == 'u')
		return (format_string(choose_ustring_maker(i, flags, 10), flags, c));
	if (c == 'x')
		return (format_string(choose_ustring_maker(i, flags, 16), flags, c));
	if (c == 'X')
	{
		return (ft_strupper(format_string(choose_ustring_maker(i, flags, 16),
						flags, c)));
	}
	return (NULL);
}

char	*handle_h(char c, t_flag *flags, va_list *args)
{
	short		i;
	char		g;

	if (flags->h)
	{
		i = (short)va_arg(*args, int);
		return (get_num(c, (int)i, flags));
	}
	if (flags->hh)
	{
		g = (char)va_arg(*args, int);
		return (get_num(c, (int)g, flags));
	}
	return (NULL);
}

char	*handle_lj(char c, t_flag *flags, va_list *args)
{
	long		i;
	long long	j;
	intmax_t	m;

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
	return (NULL);
}

int		skip_nums(char *format)
{
	int			i;

	i = 0;
	while ('0' <= format[i] && format[i] <= '9')
		i++;
	return (i);
}
