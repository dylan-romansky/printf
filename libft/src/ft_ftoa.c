/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:19:02 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/20 00:42:18 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	precision(long double dec, size_t prec)
{
	while (prec--)
		dec *= 10;
	return ((long long)(dec + 0.5));
}

int			nan_comp(double f)
{
	float		test;

	test = 0;
	if (!(f >= test) && !(f <= test))
		return (1);
	return (0);
}

char		*ft_ftoa(double f, size_t prec)
{
	long long	num;
	long long	dec;
	char		*s;
	char		*temp;

	if (f < DBL_MIN || f > DBL_MAX)
		return (ft_strdup("inf"));
	if (nan_comp(f))
		return (ft_strdup("nan"));
	num = (long long)f;
	s = ft_ltoa_base(num, 10);
	dec = precision((f - num), prec);
	if (dec)
	{
		temp = ft_strjoin(s, ".");
		free(s);
		if (dec < 0)
			dec = -dec;
		s = ft_strjoin(temp, ft_ltoa_base(dec, 10));
		free(temp);
	}
	return (s);
}
