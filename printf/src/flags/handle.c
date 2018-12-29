/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:19:16 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 19:38:27 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char	*get_num(char c, long long i, t_flag *flags)
{
	if (c == 'd' || c == 'i')
		return (format_string(ft_ltoa_base(i, 10), flags, c));
	if (c == 'o')
		return (format_string(ft_ltoa_base(i, 8), flags, c));
	if (c == 'u')
		return (format_string(ft_ltoa_base((unsigned int)i, 10), flags, c));
	if (c == 'x'c)
		return (format_string(ft_ltoa_base(i, 16), flags, c));
	if (c == 'X')
		return (ft_strupper(format_string(ft_ltoa_base(i, 16), flags, c)));
	return (NULL);
}

char	*handle_h(char c, t_flag *flags, va_list *args)
{
	short		i;
	char		g;

	if (flags->h)
	{
		i = va_arg(*args, short);
		return (get_num(c, (int)i, flags));
	}
	if (flags->hh)
	{
		g = va_arg(*args, char);
		return (get_num(c, (int)g, flags));
	}
	return (NULL);
}

char	*handle_l(char c, t_flag *flags, va_list *args)
{
	long		i;
	long long	j;

	if (flags->l)
	{
		i = va_arg(*args, long);
		return (get_num(c, i, flags));
	}
	if (flags->ll)
	{
		j = va_arg(*args, long long);
		return (get_num(c, i, flags));
	}
	return (NULL);
}

char	*handle_L(char c, t_flag *flags, va_list *args)
{
	long double	f;

	f = va_arg(*args, long double);
	return (get_float(c, f, flags);
}
