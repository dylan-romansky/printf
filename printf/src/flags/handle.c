/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:19:16 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/27 15:38:31 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char	*get_num(char c, long long i, t_flag flags)
{
	if (c == 'd' || c == 'i')
		return (format_string(ft_ltoa_base(i, 10), flags));
	if (c == 'o')
		return (format_string(ft_ltoa_base(i, 8)), flags);
	if (c == 'u')
		return (format_string(ft_ltoa_base((unsigned int)i, 10)), flags);
	if (c == 'x' || c == 'X')
		return (format_string(ft_ltoa_base(i, 16)), flags);
	return (NULL);
}

char	*handle_h(char c, t_flag flags)
{
	short		i;
	char		g;

	if (flags->h)
	{
		i = va_arg(flags->ap, short);
		return (get_num(c, (int)i, flags));
	}
	if (flags->hh)
	{
		g = va_arg(flags->ap, char);
		return (get_num(c, (int)g, flags));
	}
	return (NULL);
}

char	*handle_l(char c, t_flag flags)
{
	long		i;
	long long	j;

	if (flags->l)
	{
		i = va_arg(flags->ap, long);
		return (get_num(c, i, flags));
	}
	if (flags->ll)
	{
		j = va_arg(flags->ap, long long);
		return (get_num(c, i, flags));
	}
	return (NULL);
}
