/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numtoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:18:36 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 21:20:48 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_itoa_base(intmax_t num, int base)
{
	return (ft_itoa_base((int)num, base));
}

char	*get_ltoa_base(intmax_t num, int base)
{
	return (ft_ltoa_base((long long)num, base));
}
