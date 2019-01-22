/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:18:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/22 14:15:12 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		skip_nums(char *format)
{
	int			i;

	i = 0;
	while (('0' <= format[i] && format[i] <= '9') || format [i] == '*')
		i++;
	return (i);
}

int		flag_skip(char *format)
{
	int		i;

	i = 0;
	if (*format == '%' && *(format - 1) != '%')
		i++;
	while (format[i] && (format[i] == '+' || format[i] == ' ' ||
				(format[i] >= '0' && format[i] <= '9') || format[i] == '#' ||
				format[i] == 'h' || format[i] == 'l' || format[i] == 'L' ||
				format[i] == 'z' || format[i] == 'j' || format[i] == '.' ||
				format[i] == '-' || format[i] == '*'))
		i++;
	return (i);
}

void	flag_del(t_flag **flags)
{
	if (initflags(flags))
		free(*flags);
}

int		initflags(t_flag **input)
{
	t_flag	*new;

	new = *input;
	if (new != NULL)
	{
		new->h = 0;
		new->hh = 0;
		new->l = 0;
		new->ll = 0;
		new->el = 0;
		new->j = 0;
		new->z = 0;
		new->f = 0;
		new->percent = 0;
		new->sharp = 0;
		new->zero = 0;
		new->dash = 0;
		new->plus = 0;
		new->space = 0;
		new->dot = 0;
		new->prec = 0;
		new->width = 0;
		return (1);
	}
	return (0);
}
