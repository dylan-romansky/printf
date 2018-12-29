#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	*but;
	char	*hol;

	but = NULL;
	hol = ft_strdup("hahahahaha");

	printf("NULL %00s\n", but);
	printf("s %00.0s\np %p\nx %#x\n", hol, hol, hol);
}
