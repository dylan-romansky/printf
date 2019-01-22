#include "libft.h"

int main(int ac, char **av)
{
	char **sent;
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		sent = ft_strsplit(av[i++], ' ');
		while (sent[j])
			ft_putendl(sent[j++]);
		ft_putchar('\n');
		j = 0;
		free(sent);
	}
	return (0);
}
