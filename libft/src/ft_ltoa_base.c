/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:32:12 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/27 20:51:53 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa_base(long value, int base)
{
	char	*s;
	long	n;

	if (base == 10)
		n = value;
	else
		n = (unsigned long)value;
	if ((s = (char *)malloc(sizeof(char) * 2)))
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
			s = ft_strjoin(s, ft_strjoin(ft_itoa_base((int)(n / base), base),
						ft_itoa_base((int)(n % base), base)));
		else if (n < base && n >= 0)
		{
			s[0] = base_table((int)n);
			s[1] = '\0';
		}
		return (s);
	}
	return (NULL);
}
