/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:06:12 by dromansk          #+#    #+#             */
/*   Updated: 2018/11/08 16:38:18 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**array_join(char **sentence, char *word)
{
	char	**old;
	char	**new;
	int		i;

	old = *sentence;
	new = NULL;
	i = 0;
	while (old[i])
		i++;
	i = -1;
	if ((new = (char **)malloc(sizeof(char *) * (i + 2))))
		while (old[++i])
			new[i] = old[i];
	free (sentence);
	return (new);
}

static int		wordlen(char const *str, char d)
{
	int		i;

	i = 0;
	while (str[i] != d)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**n;
	int		len;

	if (s == NULL || !(n = (char **)malloc(sizeof(char *))))
		return (NULL);
	*n = NULL;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = wordlen(s, c);
			n = array_join(n, ft_strndup(s, (size_t)len));
			s += len;
		}
	}
	return (n);
}
