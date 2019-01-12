/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:03:00 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/11 18:43:55 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	long	v;
	int		i;

	v = (n < 0) ? -n : n;
	i = (n < 0) ? numlen(n) + 1 : numlen(n);
	if ((s = ft_strnew(i)))
	{
		while (i--)
		{
			s[i] = (v % 10) + '0';
			v /= 10;
		}
		if (n < 0)
			s[0] = '-';
		return (s);
	}
	return (NULL);
}
