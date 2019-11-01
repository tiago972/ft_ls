#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	int		opt;
	t_list	*begin_list;
	int		n_opt;

	errno = EXIT_SUCCESS;
	begin_list = NULL;
	opt = 0;
	n_opt = 0;
	// debog
	 //opt = L_LS;
	(ac == 1) ? ft_add_to_list(&begin_list, ".", "") : av++;
	n_opt = ft_parse_opt(ac, av, &opt);
	ac -= n_opt;
	av += n_opt;
	if (opt > 0 && !(*av))
		ft_add_to_list(&begin_list, ".", "");
	while (opt > 0 && *av)
	{
		if (*av[0] == '/')
			ft_add_to_list(&begin_list, "", *av);
		else
			ft_add_to_list(&begin_list, *av, "");
		av++;
	}
	//(opt & L_LS) ? ft_full_display(&begin_list, opt)
	//	: ft_simple_display(&begin_list, 1);
	ft_rec_opening(&begin_list, opt, 1);
	//debog
		//ft_debog(&begin_list);
	ft_clean_mem(&begin_list);
	return (errno == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}
