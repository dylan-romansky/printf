/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:35:01 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/23 17:09:23 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*get_char(va_list *args)
{
	char	*s;
	
	s = ft_strnew(1);
	*s = (char)va_arg(*args, int);
	return (s);
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
	if (i == 7 || i = 8)
		return (2);
	if (i == 9 || i = 10)
		return (3);
	if (i == 11)
		return (4);
}
