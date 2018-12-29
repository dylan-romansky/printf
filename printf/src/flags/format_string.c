/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:04 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 16:55:07 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* make sure this handles all the formatting variables */

char	*handle_precision(char *s, t_flag flags, char c)
{
	char	*t;
	char	*n;
	size_t	len;

	t = ft_strnew(1);
	*t = '0';
	n = s;
	len = ft_strlen(s);
	if (len < flags->prec)
		if (c != 'c' && c != 's')
			while (len < flags->prec)
				n = ft_strjoin(t, n);
	if (len > flags->prec)
		n = ft_strndup(n, len);
	return (n);
}


char	*handle_width(char *s, t_flag flags)
{
	char	*c;
	char	*n;
	size_t	len;

	c = ft_strnew(1);
	*c = (flags->zero && !flags->dash) ? '0' : ' ';
	n = s;
	len = ft_strlen(s);
	while (len < flags->width)
	{
		if (flags->dash)
			ft_strjoin(n, c);
		else
			ft_strjoin(c, n);
	}
	return (n);
}

char	*handle_space(char *s, t_flag flags)
{
	char	*c;
	char	*n;

	c = ft_strnew(1);
	*c = (*s == '-') ? '-' : ' ';
	n = s;
	n = ft_strjoin(c, n);
	return (n);
}

char	*alt(char *s, char c);
{
	char	*n;

	n = s;
	if (char c == 'x' || char c == 'X')
		n = ft_strjoin("0x", s);
	if (char c == 'o')
		n = ft_strjoin("0", s);
	return (n);
}

char	*format_string(char *s, t_flag flags, char c)
{
	char	n;

	n = s;
	if (!n && c == 's')
		n = ft_strdup("(null)");
	if (!n && c == 'p')
		n = ft_strdup("0x0");
	if (!n && c == 'c')
		n = ft_strdup("");
	if (flags->precision)
		n = handle_precision(n, flags, c);
	if (flags->sharp)
		n = alt(n, c);
	if (flags->space)
		n = handle_space(n, flags);
	if (flags->width)
		n = handle_width(n, flags);
	return (n);
}
