/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:06:38 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/04 16:22:35 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include "libft.h"

void	flag_del(t_flag **flags)
{
	if (initflags(flags))
		free (*flags);
}

char	*mirrored_join_and_free(char *buf, char **string)
{
	char			*tmp;

	tmp = ft_strjoin(buf, *string);
	ft_strclr(*string);
	free (*string);
	return (tmp);
}
