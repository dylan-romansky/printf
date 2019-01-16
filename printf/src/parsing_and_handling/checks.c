/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:32:37 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/15 21:05:50 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		check_flag(char *format)
{
	printf("check_flag %s\n", format);
	if (*format == '%' && *(format - 1) != '%')
		format++;
	while (*format && (*format == '-' || *format == '+' || *format == ' ' ||
				(*format >= '0' && *format <= '9') || *format == '#' ||
				*format == 'h' || *format == 'l' || *format == 'L' ||
				*format == 'z' || *format == 'j' || *format == '.'))
	{
		format++;
		printf("%c\n", *format);}
	if (!(*format == 'd' || *format == 'i' || *format == 'u' ||
				*format == 'o' || *format == 'x' || *format == 'X' ||
				*format == 'c' || *format == 's' || *format == 'p' ||
				*format == 'f' || *format == '%' || *format == 'U'))
	{printf("0\n");
		return (0);
	}
	printf("1\n");
	return (1);
}

int		error_handle(char **buf)
{
	*buf = ft_strdup("");
	return (0);
}
