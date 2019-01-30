/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:32:37 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 19:06:40 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_flag(char *format)
{
	while (*format && is_flag(*format, "-+ 0123456789#hlLzj.*"))
			format++;
	if (!is_flag(*format, "diuoxXcspf%%UbODF"))
		return (0);
	return (1);
}

int		error_handle(char **buf)
{
	*buf = ft_strdup("");
	return (0);
}

char	*neg_prec(char *st, t_flag *flags, int t)
{
	char	*neg;
	char	*dig;
	char	*ret;

	dig = ft_strsub(st, 1, (int)ft_strlen(st) - 1);
	neg = ft_strdup("-");
	dig = swap_n_free(handle_precision(dig, flags, t), &dig);
	ret = ft_strjoin(neg, dig);
	free(dig);
	free(neg);
	return (ret);
}

char	*format_alt(char *st, t_flag *flags, int t)
{
	char	*n;

	if (t == x || t == X || t == p)
		flags->width -= 2;
	else if (t == o)
		flags->width -= 1;
	n = handle_width(st, flags, c);
	if (t == x || t == X || t == p)
		flags->width += 2;
	else if (t == o)
		flags->width += 1;
	return (n);
}

char	*null_cases(int t)
{
	if (t == s)
		return (ft_strdup("(null)"));
	if (t == p)
		return (ft_strdup("0"));
	return (NULL);
}
