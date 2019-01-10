/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:00:58 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/09 15:02:31 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		float_check(char *s)
{
	if (ft_strequ("inf", s) || ft_strequ("nan", s))
		return (1);
	return (0);
}

int		is_nan(char *s)
{
	int		neg;
	int		dot;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			dot++;
		if (s[i] == '-')
			neg++;
		if (dot > 1 || neg > 1 || (!ft_isdigit(s[i]) && s[i] != '.'
					&& s[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}
