#include <stdio.h>
#include <limits.h>
#include "printf.h"

int		main(void){
	int strlen;
	strlen = 6;
	printf("e %.3%\n", &strlen);
	ft_printf("r %.3%\n", &strlen);
return (0);}
