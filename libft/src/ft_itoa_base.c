/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:32:12 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/18 21:29:39 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int value, int base)
{
	char *s;
	long n;

	n = (long)value;
	if ((s = (char *)malloc(sizeof(char) * 2)))
	{
		if (n < 0)
		{
			s[0] = '-';
			s[1] = '\0';
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
