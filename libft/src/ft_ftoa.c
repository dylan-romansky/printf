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

char	trimzeros(char *s)
{
	size_t		i;

	i = ft_strlen(s) - 1;
	while (i && s[i] == '0')
		i--;
	return (ft_strsub(s, 0, i));
}
	
char	*ft_ftoa(long double f)
{
	long long	num;
	long long	dec;
	char		*s;

	num = (long long)f;
	s = ft_ltoa_base(num, 10);
	dec = (long long)((f - num) * 100000000000000000 + 0.5);
	if (dec)
	{
		s = ft_strjoin(s, ".");
		if (dec < 0)
			dec = -dec;
		s = ft_strjoin(s, ft_ltoa_base(dec, 10));
	}
	return (trimzeros(s);
}
