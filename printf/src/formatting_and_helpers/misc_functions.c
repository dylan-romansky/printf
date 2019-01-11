/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/10 19:41:49 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	flag_del(t_flag **flags)
{
	if (initflags(flags))
		free(*flags);
}

void	putnstr_fd(char *s, int fd, size_t len)
{
	int		i;

	i = 0;
	while (len--)
		write(1, s + i++, fd);
}

char	*neg_prec(char *s, t_flag *flags, char c)
{
	char	*neg;
	char	*dig;
	char	*ret;

	dig = ft_strsub(s, 1, (int)ft_strlen(s) - 1);
	neg = ft_strdup("-");
	dig = swap_n_free(handle_precision(dig, flags, c), &dig);
	ret = ft_strjoin(neg, dig);
	free(dig);
	free(neg);
	return (ret);
}

char	*format_alt(char *s, t_flag *flags, char c)
{
	char	*n;

	if (c == 'x' || c == 'X' || c == 'p')
		flags->width -= 2;
	else if (c == 'o')
		flags->width -= 1;
	n = handle_width(s, flags, c);
	if (c == 'x' || c == 'X' || c == 'p')
		flags->width += 2;
	else if (c == 'o')
		flags->width += 1;
	return (n);
}

char	*null_cases(char c)
{
	if (c == 's')
		return (ft_strdup("(null)"));
	if (c == 'p')
		return (ft_strdup("0x0"));
	return (NULL);
}
