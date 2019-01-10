/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:33:12 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:09 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list args;
	char	*string;
	int		printed;

	va_start(args, format);
	string = make_string(format, &args);
	printed = putstr_printed(string, 1);
	va_end(args);
	free(string);
	return (printed);
}

int		ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list args;
	char	*string;
	int		printed;

	va_start(args, format);
	string = make_string(format, &args);
	printed = putstr_printed(string, fd);
	va_end(args);
	free(string);
	return (printed);
}
