/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/27 17:00:52 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* make sure this handles all the formatting variables */

char	*format_string(char *s, t_flag flags)
{
	char	n;

	n = s;
	if (flags->width)
		n = handle_width(n, flags);
	if (flags->precision)
		n = set_precision(n, flags);
	if (flags->space)
		n = set_space(n, flags);
	if (flags->sharp)
		n = alt(n);
}
