/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/22 14:09:35 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	putnstr_fd(char *s, int fd, size_t len)
{
	int		i;

	i = 0;
	while (len--)
		write(1, s + i++, fd);
}

char	*space_z(char *s, t_flag *flags, char c)
{
	char *n;

	flags->width -= 1;
	n = handle_width(s, flags, c);
	flags->width += 1;
	return (n);
}
