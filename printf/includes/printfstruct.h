/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfstruct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 13:28:12 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* YYYYMMDDhhmm.ss date/time format*/

#ifndef PRINTFSTRUCT_H
# define PRINTFSTRUCT_H

# include "printffun.h"

/* possible optimization, array with va_list calls populating. enumerate flag types in order to call data by storing enumerated value */
/* maybe enumerate the data type flags too and store those */

typedef enum	e_argtype
{
	d = 0, i = 0, o = 1, O = 1, u = 2, U = 2, D = 2, x = 3, X = 4, b = 5, p = 6,
	s = 7, c = 8, f = 9, F = 10, per = 11
}				t_argtype;

typedef enum	e_argsize
{
	none = 0, h = 1, hh = 2, l = 3, ll = 4, j = 5, z = 6, el = 7
}				t_argsize;

typedef struct	s_stringmake
{
	char *		(*string)(t_flag, va_list);
}				t_stringmake;

typedef struct	s_numcon
{
	int			base;
	char *		(*data)(intmax_t, int);
}				t_numcon;

typedef struct	s_arglen
{
	intmax_t	(*parse)(va_list);
}				t_arglen;

typedef struct	s_flag
{
	int			percent;
	int			sharp;
	int			zero;
	int			dash;
	int			plus;
	int			space;
	int			dot;
	int			prec;
	int			width;
	t_argsize	size;
	t_argtype	type;
}				t_flag;

typedef struct	s_types
{
	char		type;
	int			num;
}				t_types;

s_stringmake g_string
{
	{&parse_numbers},
	{&parse_pointer},
	{&parse_chars},
	{&parse_float}
};

t_numcon g_numconvert[] =
{
	{10, &ft_imaxtoa_base},
	{8, &ft_imaxtoa_base},
	{10, &ft_uimaxtoa_base},
	{10, &ft_uimaxtoa_base},
	{10, &ft_uimaxtoa_base},
	{10, &ft_uimaxtoa_base},
	{10, &ft_uimaxtoa_base}
};

t_arglen g_arglen[] =
{
	{&get_normal},
	{&get_h},
	{&get_hh},
	{&get_l},
	{&get_ll},
	{&get_j},
	{&get_z}
};

t_types g_types[] =
{
	{'d', d},
	{'i', i},
	{'o', o},
	{'O', O},
	{'u', u},
	{'U', U},
	{'D', D},
	{'x', x},
	{'X', X},
	{'b', b},
	{'p', p},
	{'s', s},
	{'c', c},
	{'f', f},
	{'F', F},
	{'%', per}
};

#endif
