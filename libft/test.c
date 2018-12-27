#include "libft.h"
#include <stdio.h>

int		main(void)
{
	void*	but;
	char*	test;

	but = ft_strnew(0);
	but = ft_strjoin(but, "nigger");
	ft_putstr(but);
	ft_putchar('\n');
	test = ft_ltoa_base((unsigned long)&but, 16);
	ft_putstr(test);
	ft_putchar('\n');
	printf("%p\n", but);
	return (0);}
