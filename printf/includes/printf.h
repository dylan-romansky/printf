/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/21 21:44:25 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* YYYYMMDDhhmm.ss date/time format*/

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

typedef struct	s_flag
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			el;
	int			j;
	int			z;
	int			f;
	int			percent;
	int			sharp;
	int			zero;
	int			dash;
	int			plus;
	int			space;
	int			dot;
	int			prec;
	int			width;
}				t_flag;

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
char			*ft_uimaxtoa(uintmax_t n, int base);
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
char			*choose_ustring_maker(intmax_t i, t_flag *flags, int base);
char			*choose_string_maker(intmax_t i, t_flag *flags);
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

#endif
