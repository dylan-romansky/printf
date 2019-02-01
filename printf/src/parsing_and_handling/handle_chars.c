/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:35:01 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/31 18:46:53 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_char(va_list *args)
{
	char	*st;
	
	st = ft_strnew(1);
	*st = (char)va_arg(*args, int);
	return (st);
}

char	*get_string(va_list *args)
{
	return (va_arg(*args, char *));
}

int		convert_type_num(int i)
{
	if (i < 6)
		return (0);
	if (i == 6)
		return (1);
	if (i == 7 || i == 8)
		return (2);
	if (i == 9 || i == 10)
		return (3);
	return (4);
}
