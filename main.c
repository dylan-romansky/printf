/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:34:29 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/03 21:12:41 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void){
	long i;

	i = -12345673865479;
	printf("expected %lx\n\n", i);
	ft_printf("result   %lx\n", i);
	return (0);}
