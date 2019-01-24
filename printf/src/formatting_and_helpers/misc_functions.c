/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/23 17:35:09 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	putnstr_fd(char *str, int fd, size_t len)
{
	int		i;

	i = 0;
	while (len--)
		write(1, str + i++, fd);
}

char	*space_z(char *str, t_flag *flags, int t)
{
	char *n;

	flags->width -= 1;
	n = handle_width(s, flags, t);
	flags->width += 1;
	return (n);
}
