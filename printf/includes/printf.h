/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 00:15:27 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* YYYYMMDDhhmm.ss date/time format*/

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

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
	char *		(*data)(intmax_t, int);
	int			base;
}				t_numcon;

typedef struct	s_arglen
{
	intmax_t	(*parse)(va_list);
}				t_arg;

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
	{&ft_imaxtoa_base, 10},
	{&ft_imaxtoa_base, 8},
	{&ft_uimaxtoa_base, 10},
	{&ft_uimaxtoa_base, 16},
	{&ft_uimaxtoa_base, 16},
	{&ft_uimaxtoa_base, 2},
	{&ft_uimaxtoa_base, 16}
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

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				make_string(const char *restrict format, va_list *args, int fd);

int				initflags(t_flag **input);
int				set_flags(t_flag **flags, char *format, va_list *args);
int				set_first(t_flag **input, char *format);
int				set_width(t_flag **input, char *format, va_list *args);
int				set_length(t_flag **input, char *format);
int				flag_skip(char *format);

long			numlen(intmax_t n);
char			*ft_uimaxtoa_base(uintmax_t n, int base);

char			*parse_numbers(char c, t_flag *flags, va_list *args);
char			*parse_chars(char c, t_flag *flags, va_list *args);
char			*parse_float(t_flag *flags, va_list *args);
char			*parse_pointer(char c, t_flag *flags, va_list *args);

char			*get_num(char c, intmax_t i, t_flag *flags);
char			*handle_h(char c, t_flag *flags, va_list *args);
char			*handle_ljz(char c, t_flag *flags, va_list *args);
int				format_string(char *s, t_flag *flags, char c, char **buf);
int				skip_nums(char *format);
int				prec(char *format, va_list *args, t_flag **input);
void			putnstr_fd(char *s, int fd, size_t len);
char			*handle_precision(char *s, t_flag *flags, char c);
char			*neg_prec(char *s, t_flag *flags, char c);
void			flag_del(t_flag **flags);
int				float_check(char *s);
char			*null_cases(char c);
char			*format_alt(char *s, t_flag *flags, char c);
char			*handle_width(char *s, t_flag *flags, char c);
char			*joining(char **string, char **buf, int len, int buflen);
int				find_size(t_flag *flags, char *str, char c);
int				nullcheck(char *s);
char			*handle_width(char *s, t_flag *flags, char c);
char			*neg_width(char *s, t_flag *flags, char c);
char			*ft_uimaxtoa_base(uintmax_t n, int base);
char			*ft_sizetoa_base(size_t n, int base);
char			*space_z(char *s, t_flag *flags, char c);
int				check_flag(char *format);
int				error_handle(char **buf);
int				set_first(t_flag **input, char *format);
int				set_more_flags(t_flag **flags, char *format, va_list *args);

#endif
