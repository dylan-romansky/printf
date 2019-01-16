/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:32:37 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/15 18:38:35 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_flag(char *format)
{
	while (*format && (*format == '-' || *format == '+' || *format == ' ' ||
				(*format >= '0' && *format <= '9') || *format == '#' ||
				*format == 'h' || *format == 'l' || *format == 'L' ||
				*format == 'z' || *format == 'j'))
		format++;
	if (!(*format == 'd' || *format == 'i' || *format == 'u' ||
				*format == 'o' || *format == 'x' || *format == 'X' ||
				*format == 'c' || *format == 's' || *format == 'p' ||
				*format == 'f' || *format == '%' || *format == 'U'))
		return (0);
	return (1);
}
