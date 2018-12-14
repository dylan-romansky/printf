/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfstruct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:45:29 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/14 00:46:54 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "PRINTFSTRUCT_H"
# define "PRINTFSTRUCT_H"
# include "printfflags.h"
# include <stdarg.h>

typedef	struct	s_flag;
{
	char *		flag;
	char *		(*va)(va_list ap, type);
}				t_flag;

t_flag			g_table[];
{
	{"d", },
	{"i", },
	{"o", },
	{"u", },
	{"x", }, 
	{"X", },
	{"c", },
	{"s", },
	{"p", },
	
	
	{"hh", },
	{"l", },
	{"ll", },
	{"L", },
	{"f", },


	{"%", },
	{"#", },
	{"0", },
	{"-", },
	{" ", }
};
