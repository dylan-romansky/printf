/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:32 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/19 17:09:35 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

/* typedef struct	s_print
{
	int			zero;
	int			precision;
	int			width;
}				t_print; */

typedef struct	s_flag
{
	va_list		ap;
	int			d;
	int			i;
	int			o;
	int			u;
	int			x;
	int			X;
	int			c;
	int			s;
	int			p;
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
	int			wild;
	int			width;
}				t_flag;

t_flag		newflag(va_list ap);
t_flag		set_flags(t_flag *flags, char *format);
t_flag		set_first(t_flag *flags, char *format);
t_flag		set_width_prelim(t_flag *flags, char *format);
int			flag_skip(char *format);

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
