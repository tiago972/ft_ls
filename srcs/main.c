#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int		opt;

	opt = 0;
	if (ac == 1)
		return (EXIT_FAILURE);
	av++;
	ft_parse_opt(ac, av, &opt);
	ft_printf("opt = %bd\n", opt);
	//if (ac == 1)
	return (0);
}
