#include <stdlib.h>
#include <stdio.h>

char		*itoatest(int n, int base)
{
	int len;
	int sign;
	char *num;
	int v;

	v = n < 0 ? -n : n;
	sign = (n < 0 && base == 10) ? 1 : 0;
	len = 2;
	while (n /= base)
		len++;
	num = (char *)malloc(sizeof(char) * (len + sign));
	num[--len + sign] = '\0';
	while (len)
	{
		num[--len + sign] = (v % base) > 9 ? (v % base) - 10 + 'A': (v % base) + '0';
		v /= base;
	}
	if (sign)
		num[0] = '-';
	return (num);
}

int			main(int ac, char **av)
{
	int i;

	i = 0;
	if ( 3 == ac)
		printf("%s\n", itoatest(atoi(av[1]), atoi(av[2])));
	return (0);
}
