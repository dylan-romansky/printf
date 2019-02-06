#include "printf.h"
#include <limits.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDWR);
	printf("%d\n", fd);
	ft_dprintf(fd, "%d\n", SHRT_MAX);
	return (0);
}
