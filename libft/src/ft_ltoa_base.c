/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:32:12 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/02 21:24:27 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa_base(long long value, int base)
{
	char		*s;
	long long	n;

	if (base == 10)
		n = value;
	else
		n = (unsigned long long)value;
	if ((s = ft_strnew(1)))
	{
		if (n < 0)
		{
			if (base == 10)
			{
				s[0] = '-';
				s[1] = '\0';
			}
			n = -n;	
		}
		if (n >= base)
			s = ft_strjoin(s, ft_strjoin(ft_ltoa_base((long long)(n / base), base),
						ft_ltoa_base((long long)(n % base), base)));
		else if (n < base && n >= 0)
		{
			s[0] = base_table((int)n);
			s[1] = '\0';
		}
		return (s);
	}
	return (NULL);
}
