/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:34:29 by dromansk          #+#    #+#             */
/*   Updated: 2018/12/13 14:36:49 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void){
	char *s;

	s = ft_strdup("big chungus");
	printf("expected %p %s %c\n", 69420, s, 'd');
	ft_printf("result   %p %s %c\n", 69420, s, 'd');
	return (0);}
