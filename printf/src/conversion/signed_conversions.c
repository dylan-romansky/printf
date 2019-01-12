/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:02:36 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/11 20:59:45 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

long		numlen(intmax_t n)
{
	long		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_imaxtoa(intmax_t n)
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
			s[i + neg] = v < 0 ? -(v % 10) + '0' : (v % 10) + '0';
			v /= 10;
		}
		if (neg)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}

char		*choose_string_maker(intmax_t i, t_flag *flags)
{
	if (flags->z)
		return (ft_uimaxtoa_base(i, 10));
	if (flags->j)
		return (ft_imaxtoa(i));
	if (flags->l)
		return (ft_ltoa((long)i));
	if (flags->ll)
		return (ft_ltoa((long long)i));
	return (ft_itoa((int)i));
}
