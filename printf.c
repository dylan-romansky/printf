/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:34:10 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/13 18:52:57 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_data(va_list args, int num);
{
	char	*string;

	string = NULL;

int		ft_printf(const char * restrict format, ...)
{
	va_list	args;
	int		num;

	va_start(list, format);
	num = 0;
	while (*format)
	{
		if (*format == '\\')
		{
			ft_putchar(*(format++));
			ft_putchar(*format);
		}
		if (*format == '%')
		{
			argnum++;
			ft_putstr(char_data(args, num, *(++format)));
	return (0);
}
