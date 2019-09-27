#include "../includes/ft_ls.h"

int		ft_parse_opt(int ac, char **av, int *opt)
{
	int		tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
			return ;
		while (av[i][j] && (tmp = ft_strlen_c("alRt", av[i][j])) > -1)
		{
			*opt |= (1 << tmp);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_init(char **av, t_list **begin_list, int ac, int first)
{

	if (!av[first] && first++)
		ft_add_file(".", begin_list);
	while (first < ac)
		ft_add_file(av[first++], begin_list);
}

int		main(int ac, char **av)
{
	int		opt;
	t_list	*begin_list;
	int		first;
	t_ls	files;

	*begin_list = NULL;
	opt = 0;
	first = 1;
	if (ac > 1)
		first = ft_parse_opt(ac, av, &opt);
	ft_init(av, &begin_list, ac, first);
	return (0);
}
