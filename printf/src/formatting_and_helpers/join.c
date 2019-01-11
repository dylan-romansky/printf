/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:12:22 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/10 18:21:51 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*force_copy(char *dst, const char *src, size_t len)
{
	size_t	i;
	
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*joining(char **string, char *buf, int len, int buflen)
{
	char	*new;

	if (!(string && *string))
		return (buf);
	if (!(new = ft_strnew(len + buflen)))
		return (NULL);
	new = force_copy(new, *string, len);
	new = (force_copy(new + len, buf, buflen) - len);
	return (new);
}

int		find_size(t_flag *flags, char *str, char c)
{
	int		len;

	len = ft_strlen(str);
	if (len > flags->prec && len > flags->width)
		return (len);
	else if (flags->prec > flags->width && c != 'f')
		return (flags->prec);
	else if (flags->prec > flags-> width && c != 'f')
		return (flags->width);
	return (1);
}
