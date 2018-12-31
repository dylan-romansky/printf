/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 19:38:27 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* possibly useless

int		round_nine(char **num)
{
	char	*s;
	int		i;

	s = *num;
	i = (int)ft_strlen(s) - 1;
	while (s[i] == '9' && i)
		s[i--] = '0';
	if (i == 0 && s[i] == '0' && s[i + 1] == '0')
		return (1);
	else
		s[i] += 1;
	return (0);
}

int		round_nums(char **num)
{
	int		i;
	char	*s;

	s = *num;
	i = (int)ft_strlen(s) - 1;
	if (s[i] == '9')
		return (round_nine(&s));
	else
		s[i] += 1;
	return (0);
}

void	round_up(char **integer, char **decimal)
{
	char	*i;
	char	*d;

	i = *integer;
	d = *decimal;
	if (round_nums(&d))
		if (round_nums(&i))
			i = ft_strjoin("1", i);
}

char	*float_precision(char *s, t_flag *flags)
{
	char	*i;
	char	*d;
	char	**split;
	int		round;

	split = ft_strsplit(s, '.');
	i = split[0];
	d = ft_strndup(split[1], flags->prec);
	round = (int)ft_strlen(d) - 1;
	if (round < (int)ft_strlen(split[1]) - 1 && '5' <= split[1][round + 1]
				&& split[1][round + 1] <= '9')
		round_up(&i, &d);
	return (ft_strjoin(i, ft_strjoin(".", d)));
}
*/
