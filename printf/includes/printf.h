/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/28 17:20:30 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft.h"

/* typedef struct	s_print
{
	int			zero;
	int			precision;
	int			width;
}				t_print; */

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
	int			prec;
	int			width;
}				t_flag;

int				ft_printf(const char * restrict format, ...);
t_flag			newflag(va_list ap);
t_flag			set_flags(t_flag *flags, char *format, va_list args);
t_flag			set_first(t_flag *flags, char *format, va_list args);
t_flag			set_width/prec(char *format, va_list args);
int				flag_skip(char *format);

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
