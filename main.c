#include "printf.h"

int		main(int ac, char **av)
{
	char *filename = "420bignig";
	char *str = "chumbles";
	ft_printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", filename, str);
	return (0);
}
