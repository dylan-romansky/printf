/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:17:17 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 21:27:53 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	numlen(int n)
{
	long		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_ltoa(long long n)
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
			s[i + neg] = v % 10 + '0';
			v /= 10;
		}
		if (neg)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}
