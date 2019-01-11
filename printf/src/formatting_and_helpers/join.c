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

char	*join_n_free(char **string, char *buf, int len, int buflen)
{
	char	*new;
	int		i;
	int		j;

	if (!string || !*string)
		return (buf);
	printf("string %s\nbuf %s\nlen %d\n buflen %d\n", *string, buf, len, buflen);//clear`
	new = ft_strnew(len + buflen);
	i = -1;
	j = 0;
	printf("i %d\n", i);
	while (++i < len)
	{
		printf("add %c\n", *string[i]);
		new[i] = *string[i];
	}
	printf("i %d\n", i);
	while (j < buflen)
	{printf("add %c\n", buf[j]);
		new[i++] = buf[j++];
	}
	printf("nuh\n");
	free(*string);
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
