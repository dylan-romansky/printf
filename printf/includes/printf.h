/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 15:04:46 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* YYYYMMDDhhmm.ss date/time format*/

/* possible optimization, array with va_list calls populating. enumerate flag types in order to call data by storing enumerated value */
/* maybe enumerate the data type flags too and store those */

#ifndef PRINTFFUN_H
# define PRINTFFUN_H
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

typedef enum	e_argtype
{
	d = 0, i = 0, o = 1, O = 1, u = 2, U = 2, D = 2, x = 3, X = 4, b = 5, p = 6,
	s = 7, c = 8, f = 9, F = 10, per = 11
}				t_argtype;

typedef enum	e_argsize
{
	none = 0, h = 1, hh = 2, l = 3, ll = 4, j = 5, z = 6, el = 7
}				t_argsize;

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

typedef struct	s_stringmake
{
	char *		(*string)(t_flag *, va_list *);
}				t_stringmake;

typedef struct	s_numcon
{
	int			base;
	char *		(*data)(intmax_t, int);
}				t_numcon;

typedef struct	s_arglen
{
	intmax_t	(*parse)(va_list *);
}				t_arglen;

typedef struct	s_types
{
	char		type;
	int			num;
}				t_types;

int				ft_printf(const char *restrict format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				make_string(const char *restrict format, va_list *args, int fd);

int				initflags(t_flag **input);
int				set_flags(t_flag **flags, char *format, va_list *args);
int				set_first(t_flag **input, char *format);
int				set_width(t_flag **input, char *format, va_list *args);
int				set_length(t_flag **input, char *format);
int				set_first(t_flag **input, char *format);
int				set_more_flags(t_flag **flags, char *format, va_list *args);
int				skip_nums(char *format);
int				flag_skip(char *format);
int				convert_type_num(int i);

char			*ft_uimaxtoa_base(intmax_t n, int base);
char			*ft_imaxtoa_base(intmax_t n, int base);
char			*ft_sizetoa_base(size_t n, int base);

int				conver_type_num(int i);
char			*parse_numbers(t_flag *flags, va_list *args);
char			*parse_chars(t_flag *flags, va_list *args);
char			*parse_float(t_flag *flags, va_list *args);
char			*parse_pointer(t_flag *flags, va_list *args);

char			*get_char(va_list *args);
char			*get_string(va_list *args);
intmax_t		get_normal(va_list *args);
intmax_t		get_h(va_list *args);
intmax_t		get_hh(va_list *args);
intmax_t		get_l(va_list *args);
intmax_t		get_ll(va_list *args);
intmax_t		get_j(va_list *args);
intmax_t		get_z(va_list *args);

int				format_string(char *st, t_flag *flags, char **buf);
int				prec(char *format, va_list *args, t_flag **input);
void			putnstr_fd(char *st, int fd, size_t len);
char			*handle_precision(char *st, t_flag *flags, int t);
char			*neg_prec(char *st, t_flag *flags, int t);
void			flag_del(t_flag **flags);
int				float_check(char *st);
char			*null_cases(int t);
char			*format_alt(char *st, t_flag *flags, int t);
char			*handle_width(char *st, t_flag *flags, int t);
char			*joining(char **string, char **buf, int len, int buflen);
int				find_size(t_flag *flags, char *str, int t);
int				nullcheck(char *st);
char			*handle_width(char *st, t_flag *flags, int t);
char			*neg_width(char *st, t_flag *flags, int t);
char			*space_z(char *st, t_flag *flags);
int				check_flag(char *format);
int				error_handle(char **buf);

t_stringmake g_string[] =
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
