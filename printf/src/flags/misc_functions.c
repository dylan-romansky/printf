/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/04 16:22:35 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*ft_ultoa_base(unsigned long long value, int base)
{
	char				*s;
	unsigned long long	n;

	n = value;
	s = ft_strnew(1);
	if (n >= (unsigned)base)
		s = ft_strjoin(ft_ultoa_base((n / base), base),
					ft_ultoa_base((n % base), base));
	else if (n < (unsigned)base)
	{
		s[0] = base_table((int)n);
		s[1] = '\0';
	}
	return (s);
}

char	*ft_uitoa_base(unsigned long value, int base)
{
	char			*s;
	unsigned long	n;

	n = value;
	s = ft_strnew(1);
	if (n >= (unsigned)base)
		s = ft_strjoin(ft_uitoa_base((n / base), base),
					ft_uitoa_base((n % base), base));
	else if (n < (unsigned)base)
	{
		s[0] = base_table((int)n);
		s[1] = '\0';
	}
	return (s);
}

char	*choose_string_maker(long long i, t_flag *flags, int base)
{
	if (flags->l)
		return (ft_ultoa_base((unsigned long)i, base));
	if (flags->ll)
		return (ft_ultoa_base((unsigned long long)i, base));
	return (ft_itoa_base((unsigned long)i, base));
}

int		putstr_printed(char *s)
{
	int				i;

	i = 0;
	while (s[i])
		write(1, (s + i++), 1);
	return (i);
}

char	*join_and_free(char **string, char **buf)
{
	char			*tmp;

	tmp = ft_strjoin(*string, *buf);
	ft_strclr(*string);
	ft_strclr(*buf);
	free (*string);
	free (*buf);
	return (tmp);
}

void	flag_del(t_flag **flags)
{
	if (initflags(flags))
		free (*flags);
}
