/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:34:29 by dromansk          #+#    #+#             */
/*   Updated: 2019/01/02 21:53:13 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void){
	char	*s;

	s = ft_strdup("bungholio");
	
	printf("expected %s\naddress: %p\n%%\n\n", s, s);
	ft_printf("result   %s\naddress: %p\n%%\n", s, s);
	return (0);}
