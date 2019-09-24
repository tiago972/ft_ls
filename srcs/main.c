#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
		while (++i < ac)
			printf("%s\n", av[i]);
	else
		printf("ta race\n");
}
