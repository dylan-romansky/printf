/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/09 17:24:08 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*handle_width(char *s, t_flag *flags, char c)
{
	char	*p;
	char	*n;
	int		len;

	len = (int)ft_strlen(s);
	n = NULL;
	p = (flags->zero && !flags->dash && ((len < flags->prec && flags->dot) ||
				(!flags->dot))) ? ft_strdup("0") : ft_strdup(" ");
	n = ft_strdup(s);
	while (len < flags->width)
	{
		if (flags->dash)
			n = swap_n_free(ft_strjoin(n, p), &n);
		else
			n = swap_n_free(ft_strjoin(p, n), &n);
		len++;
	}
	free(p);
	return (n);
}

char	*handle_space(char *s)
{
	char	*c;
	char	*n;

	c = ft_strdup(" ");
	n = NULL;
	if (s[0] != ' ' && s[0] != '-')
		n = ft_strjoin(c, s);
	else
		n = ft_strdup(s);
	free(c);
	return (n);
}

char	*handle_precision(char *s, t_flag *flags, char c)
{
	char	*t;
	char	*n;
	int		len;

	if (*s == '-')
		return (neg_prec(s, flags, c));
	t = ft_strdup("0");
	n = ft_strdup(s);
	len = (int)ft_strlen(s);
	if (len < flags->prec)
		if (c != 'c' && c != 's')
			while (len < flags->prec)
			{
				n = swap_n_free(ft_strjoin(t, n), &n);
				len++;
			}
	if (len > flags->prec && (c == 'f' || c == 's'))
		n = swap_n_free(ft_strndup(n, flags->prec), &n);
	free(t);
	return (n);
}

char	*alt(char *s, t_flag *flags, char c)
{
	char	*n;

	n = ft_strdup(s);
	if (ft_strequ(s, "0"))
		return (ft_strdup(s));
	if (s[0] != '0' && c == 'o')
		n = swap_n_free(ft_strjoin("0", s), &n);
	else if ((c == 'x' || c == 'X' || c == 'p') &&
			!(s[1] == 'x' || s[1] == 'X'))
		n = swap_n_free(ft_strjoin("0x", s), &n);
	return (n);
}

char	*format_string(char *s, t_flag *flags, char c)
{
	char	*n;

	if (!s)
		return (null_cases(c));
	if (float_check(s))
		return (s);
	n = s;
	if (flags->dot && c != 'f')
		n = swap_n_free(handle_precision(n, flags, c), &n);
	if (flags->sharp)
	{
		if (flags->zero)
			n = swap_n_free(format_alt(n, flags, c), &n);
		n = swap_n_free(alt(n, flags, c), &n);
	}
	if (flags->width)
		n = swap_n_free(handle_width(n, flags, c), &n);
	if (flags->space && c != '%')
		n = swap_n_free(handle_space(n), &n);
	return (n);
}
