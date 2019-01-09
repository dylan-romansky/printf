/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/08 17:48:34 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft.h"

void	flag_del(t_flag **flags)
{
	if (initflags(flags))
		free (*flags);
}

char	*swap_n_free(char *s, char **p)
{
	char	*tmp;

	if (p)
		tmp = *p;
	if (s != tmp && tmp)
		free(tmp);
	return (s);
}

int		putstr_printed(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, s + i++, 1);
	return (i);
}
