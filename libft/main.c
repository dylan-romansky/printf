#include "libft.h"

int		main(int ac, char **av)
{
	char	**split;
	char	d;
	int		i;

	split = NULL;
	i = 0;
	if (ac == 3)
	{
		d = av[2][0];
		split = ft_strsplit((char const *)av[1], d);
		while (split[i])
			ft_putendl(split[i++]);
		free(split);
	}
	return (0);
}
