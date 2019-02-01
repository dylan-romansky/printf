/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:19:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/31 17:19:53 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t	uget_normal(va_list *args)
{
	return((unsigned int)va_arg(*args, int));
}

intmax_t	uget_h(va_list *args)
{
	return((unsigned short)va_arg(*args, int));
}

intmax_t	uget_hh(va_list *args)
{
	return((unsigned char)va_arg(*args, int));
}
