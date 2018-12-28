/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:18:32 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/27 16:09:12 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* write flag set setters and width/precision getters */

/*t_print		init_print(void);
{
	t_print	*size;

	size = NULL;
	if((size = (t_print *)malloc(sizeof(t_print))))
	{
		size->zero = 0;
		size->precision = 0;
		size->width = 0;
	}
	return (size);
}*/

t_flag		set_flags(t_flag *flags, char *format)
{

	if (*format == '-' || *format == ' ' || *format == '0' || *format == '#')
	{
		flags = set_first(flags, format);
		while (*format == '-' || *format == ' ' || *format == '0' || *format == '#')
		{
			if (*format == '0' && *(format + 1) != '0')
				format++;
			else if (*format == '0' && *(format + 1) == '0')
			{
				format++;
				break ;
			}
			else
				format++;
		}
	}
	if (*format == '*' || *format == '.' || ('0' <= *format && *format <= '9'))
	{
		flags = set_width(flags, format);
		while (*format == '*' || *format == '.' || ('0' <= *format && *format <= '9'))
			format++;
	}
	if (*format == 'h' || *format == 'l' || *format == 'L')
	{
		flags = set_length(flags, format++);
		if (*format == 'h' || *format == 'l')
			format++;
	}
	return (flags);
}
	/* figure out where to fit this later
	if (*format == 'd' || *format == 'i' || *format == 'o' || *format == 'u'
			*format == 'x' || *format == 'X' || *format == 'c' || *format =='s'
			|| *format == 'p' || *format == 'f')
		flags = set_data; */

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
		new->L = 0;
		new->f = 0;
		new->percent = 0;
		new->sharp = 0;
		new->zero = 0;
		new->dash = 0;
		new->space = 0;
		new->prec = 0;
		new->wild = 0;
		new->width = 0;
		return (1);
	}
	return (0);
}

t_flag	newflag(void)
{
	t_flag	*new;

	if((new = (t_flag *)malloc(sizeof(t_flag))))
		if ((initflags(&new)))
			return (new);
	return (NULL);
}
