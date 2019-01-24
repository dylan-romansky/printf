/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:02:36 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/23 16:00:21 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

long		numlen(intmax_t n, int base)
{
	long		i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char		*ft_imaxtoa_base(intmax_t n, int base)
{
	char		*s;
	intmax_t	v;
	long		i;
	int			neg;

	v = n;
	neg = n < 0 ? 1 : 0;
	i = numlen(n);
	if ((s = ft_strnew(neg + i)))
	{
		s[i] = '\0';
		while (i--)
		{
			s[i + neg] = v < 0 ? base_tabe(-(v % base)) : base_table((v % base));
			v /= base;
		}
		if (neg)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}

char		*choose_string_maker(intmax_t i, t_flag *flags)
{
	if (flags->z && i != -1)
		return (ft_uimaxtoa_base(i, 10));
	else
		return (ft_imaxtoa(i));
	if (flags->j)
		return (ft_imaxtoa(i));
	if (flags->l)
		return (ft_ltoa((long)i));
	if (flags->ll)
		return (ft_ltoa((long long)i));
	return (ft_itoa((int)i));
}
