/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:57:59 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/18 21:29:52 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int value, int base)
{
	long	n;

	n = (long)value;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= base)
	{
		ft_putnbr_base((int)(n / base), base);
		ft_putnbr_base((int)(n % base), base);
	}
	else
		ft_putchar(base_table((int)n));
}
