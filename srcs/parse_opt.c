#include "../includes/ft_ls.h"

void		ft_parse_opt(int ac, char **av, int *opt)
{
	int		tmp;

	tmp = 0;
	if (**av != '-')
		return ;
	else
		(*av)++;
	while (**av && (tmp = ft_strlen_c("alrRt", **av)) > -1)
	{
		*opt |= (1 << tmp);
		(*av)++;
	}
	if (tmp == -1)
		ft_ls_error(*av, USAGE);
	if (ac > 2 && av++)
		if (**av == '-')
			ft_parse_opt(--ac, av, opt);
}
