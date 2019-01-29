/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printffun.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/29 13:27:46 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* YYYYMMDDhhmm.ss date/time format*/

#ifndef PRINTFFUN_H
# define PRINTFFUN_H
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"
# include "printfstruct.h"

/* possible optimization, array with va_list calls populating. enumerate flag types in order to call data by storing enumerated value */
/* maybe enumerate the data type flags too and store those */

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

long			numlen(intmax_t n);
char			*ft_uimaxtoa_base(uintmax_t n, int base);

int				conver_type_num(int i);
char			*parse_numbers(char c, t_flag *flags, va_list *args);
char			*parse_chars(char c, t_flag *flags, va_list *args);
char			*parse_float(t_flag *flags, va_list *args);
char			*parse_pointer(char c, t_flag *flags, va_list *args);

intmax_t		get_normal(va_list *args);
intmax_t		get_h(va_list *args);
intmax_t		get_hh(va_list *args);
intmax_t		get_char(va_list *args);
intmax_t		get_string(va_list *args);
intmax_t		get_l(va_list *args);
intmax_t		get_ll(va_list *args);
intmax_t		get_j(va_list *args);
intmax_t		get_z(va_list *args);

int				format_string(char *st, t_flag *flags, int t, char **buf);
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
char			*ft_uimaxtoa_base(uintmax_t n, int base);
char			*ft_sizetoa_base(size_t n, int base);
char			*space_z(char *st, t_flag *flags, int t);
int				check_flag(char *format);
int				error_handle(char **buf);

#endif
