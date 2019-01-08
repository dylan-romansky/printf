/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:19:02 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 20:31:13 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	precision(long double dec, size_t prec)
{
	while (prec--)
		dec *= 10;
	return ((long long)(dec + 0.5));
}

char		*ft_ftoa(long double f, size_t prec)
{
	long long	num;
	long long	dec;
	char		*s;

	num = (long long)f;
	s = ft_ltoa_base(num, 10);
	dec = precision((f - num), prec);
	if (dec)
	{
		s = ft_strjoin(s, ".");
		if (dec < 0)
			dec = -dec;
		s = ft_strjoin(s, ft_ltoa_base(dec, 10));
	}
	return (s);
}
