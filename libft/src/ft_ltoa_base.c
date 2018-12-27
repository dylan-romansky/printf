/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:32:12 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/18 21:29:39 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa_base(long value, int base)
{
	char *s;

	if ((s = (char *)malloc(sizeof(char) * 2)))
	{
		if (value < 0)
		{
			s[0] = '-';
			s[1] = '\0';
			value = -value;	
		}
		if (value >= base)
			s = ft_strjoin(s, ft_strjoin(ft_itoa_base((int)(value / base), base),
						ft_itoa_base((int)(value % base), base)));
		else if (value < base && value >= 0)
		{
			s[0] = base_table((int)value);
			s[1] = '\0';
		}
		return (s);
	}
	return (NULL);
}
