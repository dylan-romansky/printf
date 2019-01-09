/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 21:46:19 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		unumlen(unsigned long long value, unsigned int base)
{
	int					i;
	
	i = 1;
	while (value /= base)
		i++;
	return (i);
}

char		*ft_uimaxtoa_base(uintmax_t n, int base)
{
	char		*s;
	uintmax_t	v;
	long		i;

	v = n;
	i = unumlen(n, base);
	if ((s = ft_strnew(i)))
	{
		s[i] = '\0';
		while (i--)
		{
			s[i] = base_table((unsigned int)(v % base));
			v /= base;
		}
		return (s);
	}
	return (NULL);
}

char	*ft_ultoa_base(unsigned long long value, int base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	n = value;
	i = unumlen(value, base);
	s = ft_strnew(i);
	s[i] = '\0';
	while (i--)
	{
		s[i] = base_table((int)(n % base));
		n /= base;
	}
	return (s);
}

char	*ft_uitoa_base(unsigned int value, int base)
{
	char				*s;
	unsigned int		n;
	int					i;

	n = value;
	i = unumlen(value, base);
	s = ft_strnew(i);
	s[i] = '\0';
	while (i--)
	{
		s[i] = base_table((int)(n % base));
		n /= base;
	}
	return (s);
}

char	*choose_ustring_maker(intmax_t i, t_flag *flags, int base)
{
	if (flags->j)
		return (ft_uimaxtoa_base((unsigned)i, base));
	if (flags->l)
		return (ft_ultoa_base((unsigned long)i, base));
	if (flags->ll)
		return (ft_ultoa_base((unsigned long long)i, base));
	return (ft_uitoa_base((unsigned int)i, base));
}
