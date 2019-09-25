#include "../includes/ft_ls.h"



int		main(int ac, char **av)
{
	int		opt;
	t_list	begin_list;
	int		first;

	opt = 0;
	first = 1;
	if (ac > 1)
		first = ft_parse_opt(ac, av, &opt);
	while (first < ac)
	{
		ft_init();
		first++;
	}
	return (0);
}
