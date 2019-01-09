/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 20:01:22 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		unumlen(unsigned long long value, unsigned int base)
{
	int					i;
	
	i = 1;
	while (value /= base)
		i++;
	return (i);
}

int		numlen(long long value, int base)
{
	int					i;

	i = 1;
	while (value /= base)
		i++;
	return (i);
}

char	*ft_ultoa_base(unsigned long long value, int base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = value;
	i = unumlen(value, base);
	s = ft_strnew(i);
	s[i] = '\0';
	while (i--)
	{
		s[i] = base_table((int)(n % base));
		n /= base;
	}
	return (s);
}

char	*ft_uitoa_base(unsigned long value, int base)
{
	char				*s;
	unsigned long		n;
	int					i;

	n = value;
	i = unumlen(value, base);
	s = ft_strnew(i);
	s[i] = '\0';
	while (i--)
	{
		s[i] = base_table((int)(n % base));
		n /= base;
	}
	return (s);
}

char	*choose_string_maker(long long i, t_flag *flags, int base)
{
	if (flags->l)
		return (ft_ultoa_base((unsigned long)i, base));
	if (flags->ll)
		return (ft_ultoa_base((unsigned long long)i, base));
	return (ft_uitoa_base((unsigned long)i, base));
}
