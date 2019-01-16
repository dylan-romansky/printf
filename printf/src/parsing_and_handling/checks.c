/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:06:17 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/15 17:49:56 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		check_arg(char *format)
{
	format += flag_skip(format);
	if (!*format)
		return (0);
	format--;
	if (*format == '-' || *format == ' ' || (*format <= 9 &&
				*format >= '0') || *format == '#' || *format == '+' ||
				*format == '.' || *format == '*' || *format == 'l' ||
				*format == 'h' || *format == 'L' || *format == 'j' ||
				*format == 'z')
		return (1);
	else
		return (0);
}

int		error_manager(char **buf)
{
	*buf = ft_strdup("");
	return (0);
}
