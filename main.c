#include "printf.h"

int		main(int ac, char **av)
{
	char *filename = "420";
	char *str = "chumbles";
	ft_printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}\n", filename, str);
	return (0);
}
