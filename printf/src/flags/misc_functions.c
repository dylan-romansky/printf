/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 21:02:17 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft.h"

void	flag_del(t_flag **flags)
{
	if (initflags(flags))
		free (*flags);
}

char	*swap_n_free(char *s, char **p)
{
	char	*tmp;

	if (p)
		tmp = *p;
	if (s != tmp && tmp)
		free(tmp);
	return (s);
}

int		putstr_printed(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, s + i++, 1);
	return (i);
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
	free (dig);
	free (neg);
	return (ret);
}

int		is_nan(char *s)
{
	int		neg;
	int		dot;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			dot++;
		if (s[i] == '-')
			neg++;
		if (dot > 1 || neg > 1 || (!ft_isdigit(s[i]) && s[i] != '.'
				   && s[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}
