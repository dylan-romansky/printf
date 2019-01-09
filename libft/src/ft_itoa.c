/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:03:00 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 16:50:13 by dromansk         ###   ########.fr       */
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

	v = n;
	i = numlen(n);
	if ((s = ft_strnew(i)))
	{
		s[i] = '\0';
		while (i--)
		{
			s[i] = base_table(v % 10);
			v /= 10;
		}
		return (s);
	}
	return (NULL);
}
