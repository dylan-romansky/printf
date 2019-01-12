/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:37:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/11 20:53:04 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*space_z(char *s, t_flag *flags, char c)
{
	char *n;

	flags->width -= 1;
	n = handle_width(s, flags, c);
	flags->width += 1;
	return (n);
}
