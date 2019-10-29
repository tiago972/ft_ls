#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int		opt;
	t_list	*begin_list;

	errno = EXIT_SUCCESS;
	begin_list = NULL;
	opt = 0;
	if (ac == 1)
		ft_add_to_list(&begin_list, ".", "");
	else
		av++;
	av += ft_parse_opt(ac, av, &opt);
	if (ac > 1 && !(*av))
		ft_add_to_list(&begin_list, ".", "");
	while (ac > 1 && *av)
	{
		ft_add_to_list(&begin_list, *av, "");
		av++;
	}
	ft_rec_opening(&begin_list, opt, 1);
	ft_clean_mem(&begin_list);
	return (errno == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}
