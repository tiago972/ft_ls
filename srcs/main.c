#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int		opt;
	t_list	*begin_list;

	errno = EXIT_SUCCESS;
	begin_list = NULL;
	opt = 0;
	if (ac == 1)
		return (EXIT_FAILURE);
	else
		av++;
	av += ft_parse_opt(ac, av, &opt);
	while (av && *av)
	{
		ft_add_to_list(&begin_list, *av, "");
		av++;
	}
	ft_dispatch_opening(&begin_list, opt);
	//ft_debog(&begin_list);
	return (errno == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}
