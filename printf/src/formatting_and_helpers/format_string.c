/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/11 20:57:52 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*handle_width(char *s, t_flag *flags, char c)
{
	char	*p;
	char	*n;
	int		len;

	if (s[0] == '-' && flags->zero)
		return (neg_width(s, flags, c));
	len = (c == 'c') ? 1 : (int)ft_strlen(s);
	n = NULL;
	p = (flags->zero && !flags->dash && ((len < flags->prec && flags->dot) ||
				(!flags->dot))) ? ft_strdup("0") : ft_strdup(" ");
	n = ft_strdup(s);
	while (len < flags->width)
	{
		if (flags->dash)
			n = swap_n_free((nullcheck(s)) ?  ft_strjoin_len(n, p, len, 1) :
					ft_strjoin(n, p), &n);
		else
			n = swap_n_free(ft_strjoin(p, n), &n);
		len++;
	}
	free(p);
	return (n);
}

char	*handle_space(char *s, t_flag *flags, char c)
{
	char	*nc;
	char	*n;

	n = ft_strdup(s);
	if (flags->zero)
		n = swap_n_free(space_z(s, flags, c), &n);
	nc = (flags->plus) ? ft_strdup("+") : ft_strdup(" ");
	if (s[0] != ' ' && s[0] != '-' && s[0] != '+')
	{
		n = swap_n_free(ft_strjoin(nc, n), &n);
	}
	free(nc);
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
	if (len > flags->prec && (c == 's' || c == 'p' || ft_strequ("0", s)))
		n = swap_n_free(ft_strndup(n, flags->prec), &n);
	if (len < flags->prec)
		if (c != 'c' && c != 's')
			while (len < flags->prec)
			{
				n = swap_n_free(ft_strjoin(t, n), &n);
				len++;
			}
	return (n);
}

char	*alt(char *s, t_flag *flags, char c)
{
	char	*n;

	if (ft_strequ(s, "0"))
		return (ft_strdup(s));
	if (flags->zero)
		n = format_alt(s, flags, c);
	else
		n = ft_strdup(s);
	if (n[0] != '0' && c == 'o')
		n = swap_n_free(ft_strjoin("0", n), &n);
	else if ((c == 'x' || c == 'X' || c == 'p') &&
			!(n[1] == 'x' || n[1] == 'X'))
		n = swap_n_free(ft_strjoin("0x", n), &n);
	return (n);
}

int		format_string(char *s, t_flag *flags, char c, char **buf)
{
	char	*n;

	if (!s)
	{
		*buf = null_cases(c);
		return (ft_strlen(*buf));
	}
	if (c == 'f' && float_check(s))
	{
		*buf = s;
		return (ft_strlen(s));
	}
	n = s;
	if (flags->dot && c != 'f' && c != '%')
		n = swap_n_free(handle_precision(n, flags, c), &n);
	if (flags->sharp && (!flags->dot || c == 'o'))
		n = swap_n_free(alt(n, flags, c), &n);
	if ((flags->space || flags->plus) && (c == 'i' || c == 'd'))
		n = swap_n_free(handle_space(n, flags, c), &n);
	if (flags->width)
		n = swap_n_free(handle_width(n, flags, c), &n);
	if (c == 'X')
		n = ft_strupper(n);
	*buf = n;
	return (find_size(flags, n, c));
}
