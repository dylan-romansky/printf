/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 20:00:58 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 13:18:32 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printffun.h"
#include "printfstruct.h"

int		float_check(char *st)
{
	if (ft_strequ("inf", st) || ft_strequ("nan", st))
		return (1);
	return (0);
}

int		is_nan(char *st)
{
	int		neg;
	int		dot;
	int		i;

	i = 0;
	while (st[i])
	{
		if (st[i] == '.')
			dot++;
		if (st[i] == '-')
			neg++;
		if (dot > 1 || neg > 1 || (!ft_isdigit(st[i]) && st[i] != '.'
					&& st[i] != '-'))
			return (1);
		i++;
	}
	return (0);
}
