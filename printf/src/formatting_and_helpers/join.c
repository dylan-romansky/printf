/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:12:22 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/11 19:19:55 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

char	*neg_width(char *s, t_flag *flags, char c)
{
	char *neg;
	char *dig;

	neg = ft_strdup("-");
	flags->width -= 1;
	dig = handle_width(s + 1, flags, c);
	flags->width += 1;
	return (ft_strjoin(neg, dig));
}

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

char	*joining(char **string, char **buf, int len, int buflen)
{
	char	*new;

	if (!(string && *string))
		return (*buf);
	if (!(new = ft_strnew(len + buflen)))
		return (NULL);
	new = force_copy(new, *string, len);
	new = (force_copy(new + len, *buf, buflen) - len);
	free(*string);
	free(*buf);
	return (new);
}

int		find_size(t_flag *flags, char *str, char c)
{
	int		len;

	len = (int)ft_strlen(str);
	if ((len > flags->prec && len > flags->width) || c == 's')
		return (len);
	else if (flags->dot && flags->prec > flags->width && c != 'f' && c != 'c')
		return (flags->prec);
	else if ((!flags->dot && flags->width) || (flags->prec < flags->width))
		return (flags->width);
	if (c == 'c')
		return (1);
	return (0);
}

int		nullcheck(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\0')
			return (0);
	return (1);
}
