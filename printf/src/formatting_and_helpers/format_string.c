/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/10 20:43:38 by dromansk         ###   ########.fr       */
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

char	*handle_space(char *s, t_flag *flags)
{
	char	*c;
	char	*n;

	c = (flags->plus) ? ft_strdup("+") : ft_strdup(" ");
	n = NULL;
	if (s[0] != ' ' && s[0] != '-' && s[0] != '+')
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
	if ((c == 's' || ft_strequ(n, "0")) && len > flags->prec)
		n = swap_n_free(ft_strndup(n, flags->prec), &n);
	free(t);
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
	if (flags->dot && c != 'f')
		n = swap_n_free(handle_precision(n, flags, c), &n);
	if (flags->sharp && !flags->dot)
		n = swap_n_free(alt(n, flags, c), &n);
	if (flags->width)
		n = swap_n_free(handle_width(n, flags, c), &n);
	if ((flags->space || flags->plus) && (c == 'i' || c == 'd'))
		n = swap_n_free(handle_space(n, flags), &n);
	if (c == 'X')
		n = ft_strupper(n);
	*buf = n;
	return (find_size(flags, n, c));
}
