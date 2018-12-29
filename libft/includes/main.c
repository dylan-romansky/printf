#include <stdio.h>
#include "libft.h"

int		main(void)
{
	double	f;
	long double	d;

	f = 1.111111111111111;
	d = 1.11111111111111111111111111;

	printf("%.19f\n%.19Lf\n%s\n%s", f, d, ft_ftoa(f), ft_ftoa(d));
	return (0);
}
