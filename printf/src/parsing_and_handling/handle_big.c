/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:08:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 13:17:52 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printffun.h"
#include "printfstruct.h"

intmax_t	get_l(va_list *args)
{
	return (va_arg(*args, long));
}

intmax_t	get_ll(va_list *args)
{
	return (va_arg(*args, long long));
}

intmax_t	get_j(va_list *args)
{
	return (va_arg(*args, intmax_t));
}

intmax_t	get_z(va_list *args)
{
	return (va_arg(*args, ssize_t));
}