#include "../includes/ft_ls.h"

int			ft_parse_opt(int ac, char **av, int *opt)
{
	int		tmp;

	tmp = 0;
	if (**av != '-')
		return (0) ;
	else
		(*av)++;
	while (**av && (tmp = ft_strlen_c("alRrt", **av)) > -1)
	{
		*opt |= (1 << tmp);
		(*av)++;
	}
	if (tmp == -1)
		ft_ls_error(*av, USAGE);
	if (ac > 2 && av++)
		if (**av == '-')
			return (1 + ft_parse_opt(--ac, av, opt));
	return (1);
}

void		ft_dispatch_opt(t_list **begin_list, int opt)
{
	ft_sort_ascii(begin_list, opt); 
	ft_sort_time(begin_list, opt);
	ft_simple_display(begin_list, opt, ft_max_len(begin_list, opt));
	/*
	(opt & L_LS) ? ft_full_display(begin_list) : ft_simple_display(begin_list);*/
	//ft_debog(begin_list);
}
