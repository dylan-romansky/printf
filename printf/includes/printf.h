/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/02 22:28:29 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_flag
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			L;
	int			f;
	int			percent;
	int			sharp;
	int			zero;
	int			dash;
	int			space;
	int			dot;
	int			prec;
	int			width;
}				t_flag;

int				ft_printf(const char * restrict format, ...);
int				initflags(t_flag **input);
int				set_flags(t_flag **flags, char *format, va_list *args);
int				set_first(t_flag **input, char *format);
int				set_width_and_prec(char *format, va_list *args);
int				set_width(t_flag **input, char *format, va_list *args);
int				set_length(t_flag **input, char *format);
int				flag_skip(char *format);
char			*parse_numbers(char c, t_flag *flags, va_list *args);
char			*parse_chars(char c, t_flag *flags, va_list *args);
char			*parse_float(char c, t_flag *flags, va_list *args);
char			*parse_pointer(char c, t_flag *flags, va_list *args);
char			*get_num(char c, long long i, t_flag *flags);
char			*handle_h(char c, t_flag *flags, va_list *args);
char			*handle_l(char c, t_flag *flags, va_list *args);
char			*handle_L(char c, t_flag *flags, va_list *args);
char			*format_string(char *s, t_flag *flags, char c);
int				skip_nums(char *format);
int				prec(char *format, va_list *args, t_flag **input);
int				percentflag(char *format);

#endif

/* t_flag			g_table[];
{
	{"d", },//digit
	{"i", },//integer
	{"o", },//octal
	{"u", },//unsigned
	{"x", },//hex
	{"X", },//hex
	{"c", },//char
	{"s", },//string
	{"p", },//pointer
	{"f", },//float/double

	{"h", },//int from short
	{"hh", },//int from char
	{"l", },//long
	{"ll", },//long long
	{"L", },//for floating, is long double

	{"%", },//prints literal % char
	{"#", },//alt form. (f always has dec, oxX have 0 0x 0X respectively)
	{"0", },//how many 0 to print before number. format 0(num)
	{"-", },//left align
	{" ", }//print either ' ' or '-'
	{".*", }//variable width given in an argument before the variable argument
}; */
