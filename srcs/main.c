#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	/*
	if (!ft_parse_opt(ac, av))
		exit(EXIT_FAILURE);*/
	ft_printf_fd(2, "%s", av[ac - 1]);
	//if (ac == 1)
}
