/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_widthc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:25 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/22 14:18:42 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	get_width(char *format, va_list *args, t_flag **flags)
{
	if (*format >= '0' && *format <= '9')
	{
		(*flags)->width = ft_atoi(format);
		while ('0' <= *format && *format <= '9')
			format++;
	}
	if (*format == '*')
	{
		(*flags)->width = va_arg(*args, int);
		format++;
	}
	if (*format >= '0' && *format <= '9')
		(*flags)->width = ft_atoi(format);
	if ((*flags)->width < 0)
	{
		(*flags)->dash = 1;
		(*flags)->width = -((*flags)->width);
	}
}

int		set_width(t_flag **input, char *format, va_list *args)
{
	t_flag	*flags;

	flags = *input;
	while (*format && (('0' <= *format && *format <= '9') ||
				*format == '*' || *format == '.'))
	{
		if (('0' <= *format && *format <= '9') || *format == '*')
		{
			get_width(format, args, &flags);
			format += skip_nums(format);
		}
		printf("%d %c\n", flags->dot, *format);
		if (*format == '.')
			format += prec(format, args, input);
		if (*format == '-')
			flags->dash = 1;
		if (*format == ' ')
			flags->space = 1;
		if (*format == '#')
			flags->sharp = 1;
		if (!(*format && (('0' <= *format && *format <= '9') ||
						*format == '*' || *format == '.')))
			break ;
		format++;
	}
	return (1);
}

int		set_length(t_flag **input, char *format)
{
	t_flag	*flags;

	flags = *input;
	if (*format == 'l' && *(format + 1) == 'l')
		flags->ll = 1;
	else if (*format == 'l' && *(format + 1) != 'l')
			flags->l = 1;
	if (*format == 'h' && *(format + 1) == 'h')
		flags->hh = 1;
	else if (*format == 'h' && *(format + 1) != 'h')
		flags->h = 1;
	if (*format == 'z')
		flags->z = 1;
	if (*format == 'L')
		flags->el = 1;
	if (*format == 'j')
		flags->j = 1;
	return (1);
}
