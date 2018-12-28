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

char	*parse_numbers(char c, t_flag flags, va_list *args)
{
	if ((flags->h) || (flags->hh))
		return (handle_h(c, flags, args));
	if ((flags->l) || (flags->ll))
		return (handle_l(c. flags, args));
	if ((flags->L))
		return (handle_L(c, flags, args));
	return (format_string(get_num(c, va_arg(*args, int), flags)));
}

char	*parse_chars(char c, t_flag flags, va_list *args)
{
	if (c == 'c')
	{
		s = (char *)malloc(sizeof(char) * 2);
		s[0] = va_arg(*args, char);
		s[1] = 0;
		return (format_chars(s, flags, c));
	}
	if (c == 's')
	{
		return (format_string(va_arg(*args, char *), flags));
	}
	return (NULL);
}
