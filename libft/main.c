#include "libft.h"

int		main(int ac, char **av)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	if (ac == 2)
	{
		split = ft_strsplit((char const *)av[1], ' ');
		while (split[i])
			ft_putendl(split[i++]);
		free(split);
	}
	return (0);
}
