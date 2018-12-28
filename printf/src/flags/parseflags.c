/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 13:50:27 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/27 15:47:56 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*parse_numbers(char c, t_flag flags)
{
	if ((flags->h) || (flags->hh))
		return (handle_h(c, flags));
	if ((flags->l) || (flags->ll))
		return (handle_l(c. flags));
	if ((flags->L))
		return (handle_L(c, flags));
}

char	*parse_chars(char c, t_flag flags)
{
}
